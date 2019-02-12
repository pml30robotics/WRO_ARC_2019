/* This is a generated file, see Makefile.am for its inputs. */
static const char classify_syscall_map_strings[] = "accept\0accept4\0access\0adjtimex\0bind\0chmod\0chown\0clock_settime\0connect\0creat\0"
	"delete_module\0execve\0execveat\0faccessat\0fchmod\0fchmodat\0fchown\0fchownat\0finit_module\0fremovexattr\0"
	"fsetxattr\0fstat\0fstatfs\0futimens\0futimesat\0init_module\0kill\0lchown\0lremovexattr\0lsetxattr\0"
	"lstat\0mkdir\0mkdirat\0mknod\0mknodat\0mount\0newfstatat\0open\0openat\0readlink\0"
	"readlinkat\0recvfrom\0recvmsg\0removexattr\0rename\0renameat\0renameat2\0rmdir\0sendmsg\0sendto\0"
	"setdomainname\0setegid\0seteuid\0setfsgid\0setfsuid\0setgid\0sethostname\0setregid\0setresgid\0setresuid\0"
	"setreuid\0settimeofday\0setuid\0setxattr\0stat\0stat64\0statfs\0stime\0symlink\0symlinkat\0"
	"tgkill\0tkill\0umount2\0unlink\0unlinkat\0utime\0utimensat\0utimes";
static const unsigned classify_syscall_map_s2i_s[] = {
	0,7,15,22,31,36,42,48,62,70,
	76,90,97,106,116,123,132,139,148,161,
	174,184,190,198,207,217,229,234,241,254,
	264,270,276,284,290,298,304,315,320,327,
	336,347,356,364,376,383,392,402,408,416,
	423,437,445,453,462,471,478,490,499,509,
	519,528,541,548,557,562,569,576,582,590,
	600,607,613,621,628,637,643,653,
};
static const int classify_syscall_map_s2i_i[] = {
	14,14,8,26,15,2,2,26,16,1,
	4,13,13,8,2,2,2,2,3,2,
	2,8,8,12,12,3,19,2,2,2,
	8,5,5,27,27,6,8,1,1,1,
	1,17,17,2,7,7,7,11,18,18,
	28,25,24,25,24,25,28,25,25,24,
	24,26,24,2,8,8,8,26,9,9,
	19,19,10,11,11,12,12,12,
};
static int classify_syscall_map_s2i(const char *s, int *value) {
	size_t len, i;
	len = strlen(s);
	{ char copy[len + 1];
	for (i = 0; i < len; i++) {
		char c = s[i];
		copy[i] = GT_ISUPPER(c) ? c - 'A' + 'a' : c;
	}
	copy[i] = 0;
	return s2i__(classify_syscall_map_strings, classify_syscall_map_s2i_s, classify_syscall_map_s2i_i, 78, copy, value);
	}
}
