/* This is a generated file, see Makefile.am for its inputs. */
static const char ppc_syscall_strings[] = "_llseek\0_newselect\0_sysctl\0accept\0accept4\0access\0acct\0add_key\0adjtimex\0afs_syscall\0"
	"alarm\0bdflush\0bind\0bpf\0break\0brk\0capget\0capset\0chdir\0chmod\0"
	"chown\0chroot\0clock_adjtime\0clock_getres\0clock_gettime\0clock_nanosleep\0clock_settime\0clone\0close\0connect\0"
	"copy_file_range\0creat\0create_module\0delete_module\0dup\0dup2\0dup3\0epoll_create\0epoll_create1\0epoll_ctl\0"
	"epoll_pwait\0epoll_wait\0eventfd\0eventfd2\0execve\0execveat\0exit\0exit_group\0faccessat\0fadvise64\0"
	"fadvise64_64\0fallocate\0fanotify_init\0fanotify_mark\0fchdir\0fchmod\0fchmodat\0fchown\0fchownat\0fcntl\0"
	"fcntl64\0fdatasync\0fgetxattr\0finit_module\0flistxattr\0flock\0fork\0fremovexattr\0fsetxattr\0fstat\0"
	"fstat64\0fstatat64\0fstatfs\0fstatfs64\0fsync\0ftime\0ftruncate\0ftruncate64\0futex\0futimesat\0"
	"get_kernel_syms\0get_robust_list\0getcpu\0getcwd\0getdents\0getdents64\0getegid\0geteuid\0getgid\0getgroups\0"
	"getitimer\0getpeername\0getpgid\0getpgrp\0getpid\0getpmsg\0getppid\0getpriority\0getrandom\0getresgid\0"
	"getresuid\0getrlimit\0getrusage\0getsid\0getsockname\0getsockopt\0gettid\0gettimeofday\0getuid\0getxattr\0"
	"gtty\0idle\0init_module\0inotify_add_watch\0inotify_init\0inotify_init1\0inotify_rm_watch\0io_cancel\0io_destroy\0io_getevents\0"
	"io_setup\0io_submit\0ioctl\0ioperm\0iopl\0ioprio_get\0ioprio_set\0ipc\0kcmp\0kexec_load\0"
	"keyctl\0kill\0lchown\0lgetxattr\0link\0linkat\0listen\0listxattr\0llistxattr\0lock\0"
	"lookup_dcookie\0lremovexattr\0lseek\0lsetxattr\0lstat\0lstat64\0madvise\0membarrier\0memfd_create\0mincore\0"
	"mkdir\0mkdirat\0mknod\0mknodat\0mlock\0mlock2\0mlockall\0mmap\0mmap2\0modify_ldt\0"
	"mount\0move_pages\0mprotect\0mpx\0mq_getsetattr\0mq_notify\0mq_open\0mq_timedreceive\0mq_timedsend\0mq_unlink\0"
	"mremap\0msync\0multiplexer\0munlock\0munlockall\0munmap\0name_to_handle_at\0nanosleep\0nfsservctl\0nice\0"
	"oldfstat\0oldlstat\0oldolduname\0oldstat\0olduname\0open\0open_by_handle_at\0openat\0pause\0pciconfig_iobase\0"
	"pciconfig_read\0pciconfig_write\0perf_counter_open\0personality\0pipe\0pipe2\0pivot_root\0poll\0ppoll\0prctl\0"
	"pread\0preadv\0prlimit64\0process_vm_readv\0process_vm_writev\0prof\0profil\0pselect6\0ptrace\0putpmsg\0"
	"pwrite\0pwritev\0query_module\0quotactl\0read\0readahead\0readdir\0readlink\0readlinkat\0readv\0"
	"reboot\0recv\0recvfrom\0recvmmsg\0recvmsg\0remap_file_pages\0removexattr\0rename\0renameat\0renameat2\0"
	"request_key\0rmdir\0rt_sigaction\0rt_sigpending\0rt_sigprocmask\0rt_sigqueueinfo\0rt_sigreturn\0rt_sigsuspend\0rt_sigtimedwait\0rt_tgsigqueueinfo\0"
	"rtas\0sched_get_priority_max\0sched_get_priority_min\0sched_getaffinity\0sched_getattr\0sched_getparam\0sched_getscheduler\0sched_rr_get_interval\0sched_setaffinity\0sched_setattr\0"
	"sched_setparam\0sched_setscheduler\0sched_yield\0seccomp\0select\0send\0sendfile\0sendfile64\0sendmmsg\0sendmsg\0"
	"sendto\0set_robust_list\0set_tid_address\0setdomainname\0setfsgid\0setfsuid\0setgid\0setgroups\0sethostname\0setitimer\0"
	"setns\0setpgid\0setpriority\0setregid\0setresgid\0setresuid\0setreuid\0setrlimit\0setsid\0setsockopt\0"
	"settimeofday\0setuid\0setxattr\0sgetmask\0shutdown\0sigaction\0sigaltstack\0signal\0signalfd\0signalfd4\0"
	"sigpending\0sigprocmask\0sigreturn\0sigsuspend\0socket\0socketcall\0socketpair\0splice\0spu_create\0spu_run\0"
	"ssetmask\0stat\0stat64\0statfs\0statfs64\0stime\0stty\0subpage_prot\0swapcontext\0swapoff\0"
	"swapon\0switch_endian\0symlink\0symlinkat\0sync\0sync_file_range2\0syncfs\0sysfs\0sysinfo\0syslog\0"
	"tee\0tgkill\0time\0timer_create\0timer_delete\0timer_getoverrun\0timer_gettime\0timer_settime\0timerfd\0timerfd_gettime\0"
	"timerfd_settime\0times\0tkill\0truncate\0truncate64\0tuxcall\0ugetrlimit\0ulimit\0umask\0umount\0"
	"umount2\0uname\0unlink\0unlinkat\0unshare\0uselib\0userfaultfd\0ustat\0utime\0utimensat\0"
	"utimes\0vfork\0vhangup\0vm86\0vmsplice\0wait4\0waitid\0waitpid\0write\0writev";
static const unsigned ppc_syscall_s2i_s[] = {
	0,8,19,27,34,42,49,54,62,71,
	83,89,97,102,106,112,116,123,130,136,
	142,148,155,169,182,196,212,226,232,238,
	246,262,268,282,296,300,305,310,323,337,
	347,359,370,378,387,394,403,408,419,429,
	439,452,462,476,490,497,504,513,520,529,
	535,543,553,563,576,587,593,598,611,621,
	627,635,645,653,663,669,675,685,697,703,
	713,729,745,752,759,768,779,787,795,802,
	812,822,834,842,850,857,865,873,885,895,
	905,915,925,935,942,954,965,972,985,992,
	1001,1006,1011,1023,1041,1054,1068,1085,1095,1106,
	1119,1128,1138,1144,1151,1156,1167,1178,1182,1187,
	1198,1205,1210,1217,1227,1232,1239,1246,1256,1267,
	1272,1287,1300,1306,1316,1322,1330,1338,1349,1362,
	1370,1376,1384,1390,1398,1404,1411,1420,1425,1431,
	1442,1448,1459,1468,1472,1486,1496,1504,1520,1533,
	1543,1550,1556,1568,1576,1587,1594,1612,1622,1633,
	1638,1647,1656,1668,1676,1685,1690,1708,1715,1721,
	1738,1753,1769,1787,1799,1804,1810,1821,1826,1832,
	1838,1844,1851,1861,1878,1896,1901,1908,1917,1924,
	1932,1939,1947,1960,1969,1974,1984,1992,2001,2012,
	2018,2025,2030,2039,2048,2056,2073,2085,2092,2101,
	2111,2123,2129,2142,2156,2171,2187,2200,2214,2230,
	2248,2253,2276,2299,2317,2331,2346,2365,2387,2405,
	2419,2434,2453,2465,2473,2480,2485,2494,2505,2514,
	2522,2529,2545,2561,2575,2584,2593,2600,2610,2622,
	2632,2638,2646,2658,2667,2677,2687,2696,2706,2713,
	2724,2737,2744,2753,2762,2771,2781,2793,2800,2809,
	2819,2830,2842,2852,2863,2870,2881,2892,2899,2910,
	2918,2927,2932,2939,2946,2955,2961,2966,2979,2991,
	2999,3006,3020,3028,3038,3043,3060,3067,3073,3081,
	3088,3092,3099,3104,3117,3130,3147,3161,3175,3183,
	3199,3215,3221,3227,3236,3247,3255,3266,3273,3279,
	3286,3294,3300,3307,3316,3324,3331,3343,3349,3355,
	3365,3372,3378,3386,3391,3400,3406,3413,3421,3427,
};
static const int ppc_syscall_s2i_i[] = {
	140,142,149,330,344,33,51,269,124,137,
	27,134,327,361,17,45,183,184,12,15,
	181,61,347,247,246,248,245,120,6,328,
	379,8,127,129,41,63,316,236,315,237,
	303,238,307,314,11,362,1,234,298,233,
	254,309,323,324,133,94,297,95,289,55,
	204,148,214,353,217,143,2,220,211,108,
	197,291,100,253,118,35,93,194,221,290,
	130,299,302,182,141,202,50,49,47,80,
	105,332,132,65,20,187,64,96,359,170,
	165,76,77,147,331,340,207,78,24,212,
	32,112,128,276,275,318,277,231,228,229,
	227,230,54,101,110,274,273,117,354,268,
	271,37,16,213,9,294,329,215,216,53,
	235,219,19,210,107,196,205,365,360,206,
	39,287,14,288,150,378,152,90,192,123,
	21,301,125,56,267,266,262,265,264,263,
	163,144,201,151,153,91,345,162,168,34,
	28,84,59,18,109,5,346,286,29,200,
	198,199,319,136,42,317,203,167,281,171,
	179,320,325,351,352,44,98,280,26,188,
	180,321,166,131,3,191,89,85,296,145,
	88,336,337,343,342,239,218,38,293,357,
	270,40,173,175,174,177,172,178,176,322,
	255,159,160,223,356,155,157,161,222,355,
	154,156,158,358,82,334,186,226,349,341,
	335,300,232,121,139,138,46,81,74,104,
	350,57,97,71,169,164,70,75,66,339,
	79,23,209,68,338,67,185,48,305,313,
	73,126,119,72,326,102,333,283,279,278,
	69,106,195,99,252,25,31,310,249,115,
	87,363,83,295,36,308,348,135,116,103,
	284,250,13,240,244,243,242,241,306,312,
	311,43,208,92,193,225,190,58,60,22,
	52,122,10,292,282,86,364,62,30,304,
	251,189,111,113,285,114,272,7,4,146,
};
static int ppc_syscall_s2i(const char *s, int *value) {
	size_t len, i;
	len = strlen(s);
	{ char copy[len + 1];
	for (i = 0; i < len; i++) {
		char c = s[i];
		copy[i] = GT_ISUPPER(c) ? c - 'A' + 'a' : c;
	}
	copy[i] = 0;
	return s2i__(ppc_syscall_strings, ppc_syscall_s2i_s, ppc_syscall_s2i_i, 360, copy, value);
	}
}
static const unsigned ppc_syscall_i2s_direct[] = {
	403,593,1969,3421,1685,232,3413,262,1227,3300,
	387,130,3099,1384,136,1210,106,1668,1300,850,
	1442,3279,2737,985,2955,1917,83,1638,1715,3349,
	2961,1001,42,1633,669,3038,1205,2085,1370,2123,
	296,1799,3215,1896,112,2593,795,2793,787,779,
	49,3286,1267,1138,529,1468,2638,3266,1656,3273,
	148,3343,300,865,842,2706,2771,2753,2918,2687,
	2658,2852,2819,2610,2696,915,925,972,2724,802,
	2600,2473,3020,1647,1992,3324,2999,2018,1984,1420,
	1587,3227,675,497,513,873,2646,1901,2939,645,
	1144,2870,3081,2622,812,2927,1316,621,1676,1151,
	3378,1006,3386,3400,2991,3073,1178,663,2842,226,
	2561,3294,1431,62,1459,2830,268,1011,282,713,
	1960,834,490,89,3067,1787,71,2584,2575,0,
	759,8,587,1550,2012,3427,935,543,19,1398,
	1568,1411,1576,2419,2331,2434,2346,2453,2253,2276,
	2365,1612,1543,2677,905,1947,1821,1622,2667,895,
	1832,2187,2129,2156,2142,2214,2171,2200,1838,1932,
	142,752,116,123,2781,2485,857,1924,3372,3255,
	1974,1425,3236,685,2932,1322,627,1738,1753,1721,
	1556,768,1810,535,1330,1362,965,3221,2744,1306,
	611,992,1217,553,1246,1256,576,2073,1287,598,
	697,2387,2299,-1u,3247,2494,1119,1095,1106,1128,
	1085,2545,429,408,1272,310,337,359,2056,3104,
	3161,3147,3130,3117,212,182,169,196,2979,3092,
	3365,2946,653,439,2248,-1u,-1u,-1u,-1u,-1u,
	-1u,1496,1533,1520,1504,1486,1472,1187,54,2111,
	1198,3406,1167,1156,1041,1023,1068,2910,2899,1908,
	1826,3316,2892,3088,3391,1708,1376,1390,520,703,
	635,3307,2092,1232,3028,2001,504,419,729,2529,
	1448,745,347,3355,2800,3175,370,3043,452,2966,
	3199,3183,2809,378,323,305,1804,1054,1769,1844,
	1939,2230,462,476,1851,2863,97,238,1239,27,
	942,822,2881,2480,2522,2025,2030,2762,2713,954,
	2514,2048,2039,34,1594,1690,155,3060,2505,2632,
	1861,1878,563,1182,2405,2317,2101,2465,885,1349,
	102,394,3006,3331,1338,-1u,-1u,-1u,-1u,-1u,
	-1u,-1u,-1u,-1u,-1u,-1u,-1u,1404,246,
};
static const char *ppc_syscall_i2s(int v) {
	return i2s_direct__(ppc_syscall_strings, ppc_syscall_i2s_direct, 1, 379, v);
}
