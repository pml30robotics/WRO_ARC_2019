/* This is a generated file, see Makefile.am for its inputs. */
static const char x86_64_syscall_strings[] = "_sysctl\0accept\0accept4\0access\0acct\0add_key\0adjtimex\0afs_syscall\0alarm\0arch_prctl\0"
	"bind\0bpf\0brk\0capget\0capset\0chdir\0chmod\0chown\0chroot\0clock_adjtime\0"
	"clock_getres\0clock_gettime\0clock_nanosleep\0clock_settime\0clone\0close\0connect\0copy_file_range\0creat\0create_module\0"
	"delete_module\0dup\0dup2\0dup3\0epoll_create\0epoll_create1\0epoll_ctl\0epoll_ctl_old\0epoll_pwait\0epoll_wait\0"
	"epoll_wait_old\0eventfd\0eventfd2\0execve\0execveat\0exit\0exit_group\0faccessat\0fadvise64\0fallocate\0"
	"fanotify_init\0fanotify_mark\0fchdir\0fchmod\0fchmodat\0fchown\0fchownat\0fcntl\0fdatasync\0fgetxattr\0"
	"finit_module\0flistxattr\0flock\0fork\0fremovexattr\0fsetxattr\0fstat\0fstatfs\0fsync\0ftruncate\0"
	"futex\0futimesat\0get_kernel_syms\0get_mempolicy\0get_robust_list\0get_thread_area\0getcpu\0getcwd\0getdents\0getdents64\0"
	"getegid\0geteuid\0getgid\0getgroups\0getitimer\0getpeername\0getpgid\0getpgrp\0getpid\0getpmsg\0"
	"getppid\0getpriority\0getrandom\0getresgid\0getresuid\0getrlimit\0getrusage\0getsid\0getsockname\0getsockopt\0"
	"gettid\0gettimeofday\0getuid\0getxattr\0init_module\0inotify_add_watch\0inotify_init\0inotify_init1\0inotify_rm_watch\0io_cancel\0"
	"io_destroy\0io_getevents\0io_setup\0io_submit\0ioctl\0ioperm\0iopl\0ioprio_get\0ioprio_set\0kcmp\0"
	"kexec_file_load\0kexec_load\0keyctl\0kill\0lchown\0lgetxattr\0link\0linkat\0listen\0listxattr\0"
	"llistxattr\0lookup_dcookie\0lremovexattr\0lseek\0lsetxattr\0lstat\0madvise\0mbind\0membarrier\0memfd_create\0"
	"migrate_pages\0mincore\0mkdir\0mkdirat\0mknod\0mknodat\0mlock\0mlock2\0mlockall\0mmap\0"
	"modify_ldt\0mount\0move_pages\0mprotect\0mq_getsetattr\0mq_notify\0mq_open\0mq_timedreceive\0mq_timedsend\0mq_unlink\0"
	"mremap\0msgctl\0msgget\0msgrcv\0msgsnd\0msync\0munlock\0munlockall\0munmap\0name_to_handle_at\0"
	"nanosleep\0newfstatat\0nfsservctl\0open\0open_by_handle_at\0openat\0pause\0perf_event_open\0personality\0pipe\0"
	"pipe2\0pivot_root\0poll\0ppoll\0prctl\0pread\0preadv\0prlimit64\0process_vm_readv\0process_vm_writev\0"
	"pselect6\0ptrace\0putpmsg\0pwrite\0pwritev\0query_module\0quotactl\0read\0readahead\0readlink\0"
	"readlinkat\0readv\0reboot\0recvfrom\0recvmmsg\0recvmsg\0remap_file_pages\0removexattr\0rename\0renameat\0"
	"renameat2\0request_key\0restart_syscall\0rmdir\0rt_sigaction\0rt_sigpending\0rt_sigprocmask\0rt_sigqueueinfo\0rt_sigreturn\0rt_sigsuspend\0"
	"rt_sigtimedwait\0rt_tgsigqueueinfo\0sched_get_priority_max\0sched_get_priority_min\0sched_getaffinity\0sched_getattr\0sched_getparam\0sched_getscheduler\0sched_rr_get_interval\0sched_setaffinity\0"
	"sched_setattr\0sched_setparam\0sched_setscheduler\0sched_yield\0seccomp\0security\0select\0semctl\0semget\0semop\0"
	"semtimedop\0sendfile\0sendmmsg\0sendmsg\0sendto\0set_mempolicy\0set_robust_list\0set_thread_area\0set_tid_address\0setdomainname\0"
	"setfsgid\0setfsuid\0setgid\0setgroups\0sethostname\0setitimer\0setns\0setpgid\0setpriority\0setregid\0"
	"setresgid\0setresuid\0setreuid\0setrlimit\0setsid\0setsockopt\0settimeofday\0setuid\0setxattr\0shmat\0"
	"shmctl\0shmdt\0shmget\0shutdown\0sigaltstack\0signalfd\0signalfd4\0socket\0socketpair\0splice\0"
	"stat\0statfs\0swapoff\0swapon\0symlink\0symlinkat\0sync\0sync_file_range\0syncfs\0sysfs\0"
	"sysinfo\0syslog\0tee\0tgkill\0time\0timer_create\0timer_delete\0timer_getoverrun\0timer_gettime\0timer_settime\0"
	"timerfd\0timerfd_gettime\0timerfd_settime\0times\0tkill\0truncate\0tuxcall\0umask\0umount2\0uname\0"
	"unlink\0unlinkat\0unshare\0uselib\0userfaultfd\0ustat\0utime\0utimensat\0utimes\0vfork\0"
	"vhangup\0vmsplice\0vserver\0wait4\0waitid\0write\0writev";
static const unsigned x86_64_syscall_s2i_s[] = {
	0,8,15,23,30,35,43,52,64,70,
	81,86,90,94,101,108,114,120,126,133,
	147,160,174,190,204,210,216,224,240,246,
	260,274,278,283,288,301,315,325,339,351,
	362,377,385,394,401,410,415,426,436,446,
	456,470,484,491,498,507,514,523,529,539,
	549,562,573,579,584,597,607,613,621,627,
	637,643,653,669,683,699,715,722,729,738,
	749,757,765,772,782,792,804,812,820,827,
	835,843,855,865,875,885,895,905,912,924,
	935,942,955,962,971,983,1001,1014,1028,1045,
	1055,1066,1079,1088,1098,1104,1111,1116,1127,1138,
	1143,1159,1170,1177,1182,1189,1199,1204,1211,1218,
	1228,1239,1254,1267,1273,1283,1289,1297,1303,1314,
	1327,1341,1349,1355,1363,1369,1377,1383,1390,1399,
	1404,1415,1421,1432,1441,1455,1465,1473,1489,1502,
	1512,1519,1526,1533,1540,1547,1553,1561,1572,1579,
	1597,1607,1618,1629,1634,1652,1659,1665,1681,1693,
	1698,1704,1715,1720,1726,1732,1738,1745,1755,1772,
	1790,1799,1806,1814,1821,1829,1842,1851,1856,1866,
	1875,1886,1892,1899,1908,1917,1925,1942,1954,1961,
	1970,1980,1992,2008,2014,2027,2041,2056,2072,2085,
	2099,2115,2133,2156,2179,2197,2211,2226,2245,2267,
	2285,2299,2314,2333,2345,2353,2362,2369,2376,2383,
	2389,2400,2409,2418,2426,2433,2447,2463,2479,2495,
	2509,2518,2527,2534,2544,2556,2566,2572,2580,2592,
	2601,2611,2621,2630,2640,2647,2658,2671,2678,2687,
	2693,2700,2706,2713,2722,2734,2743,2753,2760,2771,
	2778,2783,2790,2798,2805,2813,2823,2828,2844,2851,
	2857,2865,2872,2876,2883,2888,2901,2914,2931,2945,
	2959,2967,2983,2999,3005,3011,3020,3028,3034,3042,
	3048,3055,3064,3072,3079,3091,3097,3103,3113,3120,
	3126,3134,3143,3151,3157,3164,3170,
};
static const int x86_64_syscall_s2i_i[] = {
	156,43,288,21,163,248,159,183,37,158,
	49,321,12,125,126,80,90,92,161,305,
	229,228,230,227,56,3,42,326,85,174,
	176,32,33,292,213,291,233,214,281,232,
	215,284,290,59,322,60,231,269,221,285,
	300,301,81,91,268,93,260,72,75,193,
	313,196,73,57,199,190,5,138,74,77,
	202,261,177,239,274,211,309,79,78,217,
	108,107,104,115,36,52,121,111,39,181,
	110,140,318,120,118,97,98,124,51,55,
	186,96,102,191,175,254,253,294,255,210,
	207,208,206,209,16,173,172,252,251,312,
	320,246,250,62,94,192,86,265,50,194,
	195,212,198,8,189,6,28,237,324,319,
	256,27,83,258,133,259,149,325,151,9,
	154,165,279,10,245,244,240,243,242,241,
	25,71,68,70,69,26,150,152,11,303,
	35,262,180,2,304,257,34,298,135,22,
	293,155,7,271,157,17,295,302,310,311,
	270,101,182,18,296,178,179,0,187,89,
	267,19,169,45,299,47,216,197,82,264,
	316,249,219,84,13,127,14,129,15,130,
	128,297,146,147,204,315,143,145,148,203,
	314,142,144,24,317,185,23,66,64,65,
	220,40,307,46,44,238,273,205,218,171,
	123,122,106,116,170,38,308,109,141,114,
	119,117,113,160,112,54,164,105,188,30,
	31,67,29,48,131,282,289,41,53,275,
	4,137,168,167,88,266,162,277,306,139,
	99,103,276,234,201,222,226,225,224,223,
	283,287,286,100,200,76,184,95,166,63,
	87,263,272,134,323,136,132,280,235,58,
	153,278,236,61,247,1,20,
};
static int x86_64_syscall_s2i(const char *s, int *value) {
	size_t len, i;
	len = strlen(s);
	{ char copy[len + 1];
	for (i = 0; i < len; i++) {
		char c = s[i];
		copy[i] = GT_ISUPPER(c) ? c - 'A' + 'a' : c;
	}
	copy[i] = 0;
	return s2i__(x86_64_syscall_strings, x86_64_syscall_s2i_s, x86_64_syscall_s2i_i, 327, copy, value);
	}
}
static const unsigned x86_64_syscall_i2s_direct[] = {
	1851,3164,1629,210,2778,607,1283,1715,1267,1399,
	1432,1572,90,2014,2041,2072,1098,1732,1814,1886,
	3170,23,1693,2362,2333,1512,1547,1341,1289,2706,
	2687,2693,274,278,1659,1597,782,64,2556,820,
	2400,2753,216,8,2426,1899,2418,1917,2713,81,
	1211,912,792,2760,2647,924,204,579,3120,394,
	410,3151,1177,3042,2376,2383,2369,2700,1526,1540,
	1533,1519,523,573,621,529,3011,627,729,722,
	108,484,1954,1349,2008,240,1199,3048,2805,1866,
	114,491,120,507,1182,3028,942,885,895,2857,
	2999,1799,955,2865,765,2671,2527,757,749,2572,
	835,812,2640,2621,2592,772,2534,2611,875,2601,
	865,804,2518,2509,905,94,101,2027,2099,2056,
	2085,2722,3097,1363,3072,1681,3091,2783,613,2851,
	843,2580,2299,2211,2314,2226,2133,2156,2245,1377,
	1553,1390,1561,3126,1404,1704,0,1726,70,43,
	2630,126,2823,30,2658,1415,3034,2798,2790,1892,
	2544,2495,1111,1104,246,971,260,653,1829,1842,
	1618,827,1806,52,3020,2353,935,1856,2678,1273,
	597,962,1189,539,1218,1228,562,1942,1254,584,
	3005,2883,637,2267,2179,2463,1079,1055,1066,1088,
	1045,699,1239,288,325,362,1925,738,2479,1992,
	2389,436,2888,2945,2931,2914,2901,190,160,147,
	174,415,351,315,2876,3113,3143,1297,2433,669,
	1465,1502,1489,1473,1455,1441,1159,3157,35,1980,
	1170,1127,1116,1001,983,1028,1327,1652,1355,1369,
	514,643,1607,3055,1961,1204,2813,1875,498,426,
	1790,1720,3064,2447,683,2771,2872,2828,3134,1421,
	3103,339,2734,2959,377,446,2983,2967,15,2743,
	385,301,283,1698,1014,1738,1821,2115,1665,1908,
	456,470,1745,1579,1634,133,2844,2409,2566,715,
	1755,1772,1138,549,2285,2197,1970,2345,855,1314,
	1143,86,401,3079,1303,1383,224,
};
static const char *x86_64_syscall_i2s(int v) {
	return i2s_direct__(x86_64_syscall_strings, x86_64_syscall_i2s_direct, 0, 326, v);
}
