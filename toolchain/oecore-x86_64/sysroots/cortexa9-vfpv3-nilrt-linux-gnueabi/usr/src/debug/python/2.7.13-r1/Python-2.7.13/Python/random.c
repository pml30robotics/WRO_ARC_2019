#include "Python.h"
#ifdef MS_WINDOWS
#include <windows.h>
#else
#include <fcntl.h>
#if defined(HAVE_GETRANDOM) || defined(HAVE_GETENTROPY)
#include <sys/random.h>
#endif
#endif

#ifdef Py_DEBUG
int _Py_HashSecret_Initialized = 0;
#else
static int _Py_HashSecret_Initialized = 0;
#endif

#ifdef MS_WINDOWS
typedef BOOL (WINAPI *CRYPTACQUIRECONTEXTA)(HCRYPTPROV *phProv,\
              LPCSTR pszContainer, LPCSTR pszProvider, DWORD dwProvType,\
              DWORD dwFlags );
typedef BOOL (WINAPI *CRYPTGENRANDOM)(HCRYPTPROV hProv, DWORD dwLen,\
              BYTE *pbBuffer );

static CRYPTGENRANDOM pCryptGenRandom = NULL;
/* This handle is never explicitly released. Instead, the operating
   system will release it when the process terminates. */
static HCRYPTPROV hCryptProv = 0;

static int
win32_urandom_init(int raise)
{
    HINSTANCE hAdvAPI32 = NULL;
    CRYPTACQUIRECONTEXTA pCryptAcquireContext = NULL;

    /* Obtain handle to the DLL containing CryptoAPI. This should not fail. */
    hAdvAPI32 = GetModuleHandle("advapi32.dll");
    if(hAdvAPI32 == NULL)
        goto error;

    /* Obtain pointers to the CryptoAPI functions. This will fail on some early
       versions of Win95. */
    pCryptAcquireContext = (CRYPTACQUIRECONTEXTA)GetProcAddress(
                               hAdvAPI32, "CryptAcquireContextA");
    if (pCryptAcquireContext == NULL)
        goto error;

    pCryptGenRandom = (CRYPTGENRANDOM)GetProcAddress(hAdvAPI32,
                                                     "CryptGenRandom");
    if (pCryptGenRandom == NULL)
        goto error;

    /* Acquire context */
    if (! pCryptAcquireContext(&hCryptProv, NULL, NULL,
                               PROV_RSA_FULL, CRYPT_VERIFYCONTEXT))
        goto error;

    return 0;

error:
    if (raise)
        PyErr_SetFromWindowsErr(0);
    else
        Py_FatalError("Failed to initialize Windows random API (CryptoGen)");
    return -1;
}

/* Fill buffer with size pseudo-random bytes generated by the Windows CryptoGen
   API. Return 0 on success, or -1 on error. */
static int
win32_urandom(unsigned char *buffer, Py_ssize_t size, int raise)
{
    Py_ssize_t chunk;

    if (hCryptProv == 0)
    {
        if (win32_urandom_init(raise) == -1)
            return -1;
    }

    while (size > 0)
    {
        chunk = size > INT_MAX ? INT_MAX : size;
        if (!pCryptGenRandom(hCryptProv, chunk, buffer))
        {
            /* CryptGenRandom() failed */
            if (raise)
                PyErr_SetFromWindowsErr(0);
            else
                Py_FatalError("Failed to initialized the randomized hash "
                        "secret using CryptoGen)");
            return -1;
        }
        buffer += chunk;
        size -= chunk;
    }
    return 0;
}

/* Issue #25003: Don't use getentropy() on Solaris (available since
   Solaris 11.3), it is blocking whereas os.urandom() should not block.

   Issue #29188: Don't use getentropy() on Linux since the glibc 2.24
   implements it with the getrandom() syscall which can fail with ENOSYS,
   and this error is not supported in py_getentropy() and getrandom() is called
   with flags=0 which blocks until system urandom is initialized, which is not
   the desired behaviour to seed the Python hash secret nor for os.urandom():
   see the PEP 524 which was only implemented in Python 3.6. */
#elif defined(HAVE_GETENTROPY) && !defined(sun) && !defined(linux)
#define PY_GETENTROPY 1

/* Fill buffer with size pseudo-random bytes generated by getentropy().
   Return 0 on success, or raise an exception and return -1 on error.
   If fatal is nonzero, call Py_FatalError() instead of raising an exception
   on error. */
static int
py_getentropy(unsigned char *buffer, Py_ssize_t size, int fatal)
{
    while (size > 0) {
        Py_ssize_t len = size < 256 ? size : 256;
        int res;

        if (!fatal) {
            Py_BEGIN_ALLOW_THREADS
            res = getentropy(buffer, len);
            Py_END_ALLOW_THREADS

            if (res < 0) {
                PyErr_SetFromErrno(PyExc_OSError);
                return -1;
            }
        }
        else {
            res = getentropy(buffer, len);
            if (res < 0)
                Py_FatalError("getentropy() failed");
        }

        buffer += len;
        size -= len;
    }
    return 0;
}
#endif

#ifdef __VMS
/* Use openssl random routine */
#include <openssl/rand.h>
static int
vms_urandom(unsigned char *buffer, Py_ssize_t size, int raise)
{
    if (RAND_pseudo_bytes(buffer, size) < 0) {
        if (raise) {
            PyErr_Format(PyExc_ValueError,
                         "RAND_pseudo_bytes");
        } else {
            Py_FatalError("Failed to initialize the randomized hash "
                          "secret using RAND_pseudo_bytes");
        }
        return -1;
    }
    return 0;
}
#endif /* __VMS */


#if !defined(MS_WINDOWS) && !defined(__VMS)

static struct {
    int fd;
    dev_t st_dev;
    ino_t st_ino;
} urandom_cache = { -1 };

/* Read size bytes from /dev/urandom into buffer.
   Call Py_FatalError() on error. */
static void
dev_urandom_noraise(unsigned char *buffer, Py_ssize_t size)
{
    int fd;
    Py_ssize_t n;

    assert (0 < size);

    fd = open("/dev/urandom", O_RDONLY);
    if (fd < 0)
        Py_FatalError("Failed to open /dev/urandom");

    while (0 < size)
    {
        do {
            n = read(fd, buffer, (size_t)size);
        } while (n < 0 && errno == EINTR);
        if (n <= 0)
        {
            /* stop on error or if read(size) returned 0 */
            Py_FatalError("Failed to read bytes from /dev/urandom");
            break;
        }
        buffer += n;
        size -= (Py_ssize_t)n;
    }
    close(fd);
}

/* Read size bytes from /dev/urandom into buffer.
   Return 0 on success, raise an exception and return -1 on error. */
static int
dev_urandom_python(char *buffer, Py_ssize_t size)
{
    int fd;
    Py_ssize_t n;
    struct stat st;
    int attr;

    if (size <= 0)
        return 0;

    if (urandom_cache.fd >= 0) {
        /* Does the fd point to the same thing as before? (issue #21207) */
        if (fstat(urandom_cache.fd, &st)
            || st.st_dev != urandom_cache.st_dev
            || st.st_ino != urandom_cache.st_ino) {
            /* Something changed: forget the cached fd (but don't close it,
               since it probably points to something important for some
               third-party code). */
            urandom_cache.fd = -1;
        }
    }
    if (urandom_cache.fd >= 0)
        fd = urandom_cache.fd;
    else {
        Py_BEGIN_ALLOW_THREADS
        fd = open("/dev/urandom", O_RDONLY);
        Py_END_ALLOW_THREADS
        if (fd < 0)
        {
            if (errno == ENOENT || errno == ENXIO ||
                errno == ENODEV || errno == EACCES)
                PyErr_SetString(PyExc_NotImplementedError,
                                "/dev/urandom (or equivalent) not found");
            else
                PyErr_SetFromErrno(PyExc_OSError);
            return -1;
        }

        /* try to make the file descriptor non-inheritable, ignore errors */
        attr = fcntl(fd, F_GETFD);
        if (attr >= 0) {
            attr |= FD_CLOEXEC;
            (void)fcntl(fd, F_SETFD, attr);
        }

        if (urandom_cache.fd >= 0) {
            /* urandom_fd was initialized by another thread while we were
               not holding the GIL, keep it. */
            close(fd);
            fd = urandom_cache.fd;
        }
        else {
            if (fstat(fd, &st)) {
                PyErr_SetFromErrno(PyExc_OSError);
                close(fd);
                return -1;
            }
            else {
                urandom_cache.fd = fd;
                urandom_cache.st_dev = st.st_dev;
                urandom_cache.st_ino = st.st_ino;
            }
        }
    }

    Py_BEGIN_ALLOW_THREADS
    do {
        do {
            n = read(fd, buffer, (size_t)size);
        } while (n < 0 && errno == EINTR);
        if (n <= 0)
            break;
        buffer += n;
        size -= (Py_ssize_t)n;
    } while (0 < size);
    Py_END_ALLOW_THREADS

    if (n <= 0)
    {
        /* stop on error or if read(size) returned 0 */
        if (n < 0)
            PyErr_SetFromErrno(PyExc_OSError);
        else
            PyErr_Format(PyExc_RuntimeError,
                         "Failed to read %zi bytes from /dev/urandom",
                         size);
        return -1;
    }
    return 0;
}

static void
dev_urandom_close(void)
{
    if (urandom_cache.fd >= 0) {
        close(urandom_cache.fd);
        urandom_cache.fd = -1;
    }
}


#endif /* !defined(MS_WINDOWS) && !defined(__VMS) */

/* Fill buffer with pseudo-random bytes generated by a linear congruent
   generator (LCG):

       x(n+1) = (x(n) * 214013 + 2531011) % 2^32

   Use bits 23..16 of x(n) to generate a byte. */
static void
lcg_urandom(unsigned int x0, unsigned char *buffer, size_t size)
{
    size_t index;
    unsigned int x;

    x = x0;
    for (index=0; index < size; index++) {
        x *= 214013;
        x += 2531011;
        /* modulo 2 ^ (8 * sizeof(int)) */
        buffer[index] = (x >> 16) & 0xff;
    }
}

/* Fill buffer with size pseudo-random bytes from the operating system random
   number generator (RNG). It is suitable for most cryptographic purposes
   except long living private keys for asymmetric encryption.

   Return 0 on success, raise an exception and return -1 on error. */
int
_PyOS_URandom(void *buffer, Py_ssize_t size)
{
    if (size < 0) {
        PyErr_Format(PyExc_ValueError,
                     "negative argument not allowed");
        return -1;
    }
    if (size == 0)
        return 0;

#ifdef MS_WINDOWS
    return win32_urandom((unsigned char *)buffer, size, 1);
#elif defined(PY_GETENTROPY)
    return py_getentropy(buffer, size, 0);
#else
# ifdef __VMS
    return vms_urandom((unsigned char *)buffer, size, 1);
# else
    return dev_urandom_python((char*)buffer, size);
# endif
#endif
}

void
_PyRandom_Init(void)
{
    char *env;
    void *secret = &_Py_HashSecret;
    Py_ssize_t secret_size = sizeof(_Py_HashSecret_t);

    if (_Py_HashSecret_Initialized)
        return;
    _Py_HashSecret_Initialized = 1;

    /*
      By default, hash randomization is disabled, and only
      enabled if PYTHONHASHSEED is set to non-empty or if
      "-R" is provided at the command line:
    */
    if (!Py_HashRandomizationFlag) {
        /* Disable the randomized hash: */
        memset(secret, 0, secret_size);
        return;
    }

    /*
      Hash randomization is enabled.  Generate a per-process secret,
      using PYTHONHASHSEED if provided.
    */

    env = Py_GETENV("PYTHONHASHSEED");
    if (env && *env != '\0' && strcmp(env, "random") != 0) {
        char *endptr = env;
        unsigned long seed;
        seed = strtoul(env, &endptr, 10);
        if (*endptr != '\0'
            || seed > 4294967295UL
            || (errno == ERANGE && seed == ULONG_MAX))
        {
            Py_FatalError("PYTHONHASHSEED must be \"random\" or an integer "
                          "in range [0; 4294967295]");
        }
        if (seed == 0) {
            /* disable the randomized hash */
            memset(secret, 0, secret_size);
        }
        else {
            lcg_urandom(seed, (unsigned char*)secret, secret_size);
        }
    }
    else {
#ifdef MS_WINDOWS
        (void)win32_urandom((unsigned char *)secret, secret_size, 0);
#elif __VMS
        vms_urandom((unsigned char *)secret, secret_size, 0);
#elif defined(PY_GETENTROPY)
        (void)py_getentropy(secret, secret_size, 1);
#else
        dev_urandom_noraise(secret, secret_size);
#endif
    }
}

void
_PyRandom_Fini(void)
{
#ifdef MS_WINDOWS
    if (hCryptProv) {
        CryptReleaseContext(hCryptProv, 0);
        hCryptProv = 0;
    }
#elif defined(PY_GETENTROPY)
    /* nothing to clean */
#else
    dev_urandom_close();
#endif
}
