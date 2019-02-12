/* This is a generated file, see Makefile.am for its inputs. */
static const char s390x_syscall_strings[] = "_sysctl\0accept4\0access\0acct\0add_key\0adjtimex\0afs_syscall\0alarm\0bdflush\0bind\0"
	"bpf\0brk\0capget\0capset\0chdir\0chmod\0chown\0chroot\0clock_adjtime\0clock_getres\0"
	"clock_gettime\0clock_nanosleep\0clock_settime\0clone\0close\0connect\0copy_file_range\0creat\0create_module\0delete_module\0"
	"dup\0dup2\0dup3\0epoll_create\0epoll_create1\0epoll_ctl\0epoll_pwait\0epoll_wait\0eventfd\0eventfd2\0"
	"execve\0execveat\0exit\0exit_group\0faccessat\0fadvise64\0fallocate\0fanotify_init\0fanotify_mark\0fchdir\0"
	"fchmod\0fchmodat\0fchown\0fchownat\0fcntl\0fdatasync\0fgetxattr\0finit_module\0flistxattr\0flock\0"
	"fork\0fremovexattr\0fsetxattr\0fstat\0fstatfs\0fstatfs64\0fsync\0ftruncate\0futex\0futimesat\0"
	"get_kernel_syms\0get_robust_list\0getcpu\0getcwd\0getdents\0getegid\0geteuid\0getgid\0getgroups\0getitimer\0"
	"getpeername\0getpgid\0getpgrp\0getpid\0getpmsg\0getppid\0getpriority\0getrandom\0getresgid\0getresuid\0"
	"getrlimit\0getrusage\0getsid\0getsockname\0getsockopt\0gettid\0gettimeofday\0getuid\0getxattr\0idle\0"
	"init_module\0inotify_add_watch\0inotify_init\0inotify_init1\0inotify_rm_watch\0io_cancel\0io_destroy\0io_getevents\0io_setup\0io_submit\0"
	"ioctl\0ioprio_get\0ioprio_set\0ipc\0kcmp\0kexec_load\0keyctl\0kill\0lchown\0lgetxattr\0"
	"link\0linkat\0listen\0listxattr\0llistxattr\0lremovexattr\0lseek\0lsetxattr\0lstat\0madvise\0"
	"membarrier\0memfd_create\0mincore\0mkdir\0mkdirat\0mknod\0mknodat\0mlock\0mlock2\0mlockall\0"
	"mmap\0mount\0mprotect\0mq_getsetattr\0mq_notify\0mq_open\0mq_timedreceive\0mq_timedsend\0mq_unlink\0mremap\0"
	"msync\0munlock\0munlockall\0munmap\0name_to_handle_at\0nanosleep\0newfstatat\0nfsservctl\0nice\0open\0"
	"open_by_handle_at\0openat\0pause\0perf_event_open\0personality\0pipe\0pipe2\0pivot_root\0poll\0ppoll\0"
	"prctl\0pread\0preadv\0prlimit64\0process_vm_readv\0process_vm_writev\0pselect6\0ptrace\0putpmsg\0pwrite\0"
	"pwritev\0query_module\0quotactl\0read\0readahead\0readdir\0readlink\0readlinkat\0readv\0reboot\0"
	"recvfrom\0recvmmsg\0recvmsg\0remap_file_pages\0removexattr\0rename\0renameat\0renameat2\0request_key\0rmdir\0"
	"rt_sigaction\0rt_sigpending\0rt_sigprocmask\0rt_sigqueueinfo\0rt_sigreturn\0rt_sigsuspend\0rt_sigtimedwait\0rt_tgsigqueueinfo\0s390_pci_mmio_read\0s390_pci_mmio_write\0"
	"s390_runtime_instr\0sched_get_priority_max\0sched_get_priority_min\0sched_getaffinity\0sched_getattr\0sched_getparam\0sched_getscheduler\0sched_rr_get_interval\0sched_setaffinity\0sched_setattr\0"
	"sched_setparam\0sched_setscheduler\0sched_yield\0seccomp\0select\0sendfile\0sendmmsg\0sendmsg\0sendto\0set_robust_list\0"
	"set_tid_address\0setdomainname\0setfsgid\0setfsuid\0setgid\0setgroups\0sethostname\0setitimer\0setns\0setpgid\0"
	"setpriority\0setregid\0setresgid\0setresuid\0setreuid\0setrlimit\0setsid\0setsockopt\0settimeofday\0setuid\0"
	"setxattr\0shutdown\0sigaction\0sigaltstack\0signal\0signalfd\0signalfd4\0sigpending\0sigprocmask\0sigreturn\0"
	"sigsuspend\0socket\0socketcall\0socketpair\0splice\0stat\0statfs\0statfs64\0swapoff\0swapon\0"
	"symlink\0symlinkat\0sync\0sync_file_range\0syncfs\0sysfs\0sysinfo\0syslog\0tee\0tgkill\0"
	"timer_create\0timer_delete\0timer_getoverrun\0timer_gettime\0timer_settime\0timerfd\0timerfd_create\0timerfd_gettime\0timerfd_settime\0times\0"
	"tkill\0truncate\0umask\0umount\0umount2\0uname\0unlink\0unlinkat\0unshare\0uselib\0"
	"userfaultfd\0ustat\0utime\0utimensat\0utimes\0vfork\0vhangup\0vmsplice\0wait4\0waitid\0"
	"write\0writev";
static const unsigned s390x_syscall_s2i_s[] = {
	0,8,16,23,28,36,45,57,63,71,
	76,80,84,91,98,104,110,116,123,137,
	150,164,180,194,200,206,214,230,236,250,
	264,268,273,278,291,305,315,327,338,346,
	355,362,371,376,387,397,407,417,431,445,
	452,459,468,475,484,490,500,510,523,534,
	540,545,558,568,574,582,592,598,608,614,
	624,640,656,663,670,679,687,695,702,712,
	722,734,742,750,757,765,773,785,795,805,
	815,825,835,842,854,865,872,885,892,901,
	906,918,936,949,963,980,990,1001,1014,1023,
	1033,1039,1050,1061,1065,1070,1081,1088,1093,1100,
	1110,1115,1122,1129,1139,1150,1163,1169,1179,1185,
	1193,1204,1217,1225,1231,1239,1245,1253,1259,1266,
	1275,1280,1286,1295,1309,1319,1327,1343,1356,1366,
	1373,1379,1387,1398,1405,1423,1433,1444,1455,1460,
	1465,1483,1490,1496,1512,1524,1529,1535,1546,1551,
	1557,1563,1569,1576,1586,1603,1621,1630,1637,1645,
	1652,1660,1673,1682,1687,1697,1705,1714,1725,1731,
	1738,1747,1756,1764,1781,1793,1800,1809,1819,1831,
	1837,1850,1864,1879,1895,1908,1922,1938,1956,1975,
	1995,2014,2037,2060,2078,2092,2107,2126,2148,2166,
	2180,2195,2214,2226,2234,2241,2250,2259,2267,2274,
	2290,2306,2320,2329,2338,2345,2355,2367,2377,2383,
	2391,2403,2412,2422,2432,2441,2451,2458,2469,2482,
	2489,2498,2507,2517,2529,2536,2545,2555,2566,2578,
	2588,2599,2606,2617,2628,2635,2640,2647,2656,2664,
	2671,2679,2689,2694,2710,2717,2723,2731,2738,2742,
	2749,2762,2775,2792,2806,2820,2828,2843,2859,2875,
	2881,2887,2896,2902,2909,2917,2923,2930,2939,2947,
	2954,2966,2972,2978,2988,2995,3001,3009,3018,3024,
	3031,3037,
};
static const int s390x_syscall_s2i_i[] = {
	149,364,33,51,278,124,137,27,134,361,
	351,45,184,185,12,15,212,61,337,261,
	260,262,259,120,6,362,375,8,127,129,
	41,63,326,249,327,250,312,251,318,323,
	11,354,1,248,300,253,314,332,333,133,
	94,299,207,291,55,148,229,344,232,143,
	2,235,226,108,100,266,118,93,238,292,
	130,305,311,183,141,202,201,200,205,105,
	368,132,65,20,188,64,96,349,211,209,
	191,77,147,367,365,236,78,199,227,112,
	128,285,284,324,286,247,244,245,243,246,
	54,283,282,117,343,277,280,37,198,228,
	9,296,363,230,231,234,19,225,107,219,
	356,350,218,39,289,14,290,150,374,152,
	90,21,125,276,275,271,274,273,272,163,
	144,151,153,91,335,162,293,169,34,5,
	336,288,29,331,136,42,325,217,168,302,
	172,180,328,334,340,341,301,26,189,181,
	329,167,131,3,222,89,85,298,145,88,
	371,357,372,267,233,38,295,347,279,40,
	174,176,175,178,173,179,177,330,353,352,
	342,159,160,240,346,155,157,161,239,345,
	154,156,158,348,142,187,358,370,369,304,
	252,121,216,215,214,206,74,104,339,57,
	97,204,210,208,203,75,66,366,79,213,
	224,373,67,186,48,316,322,73,126,119,
	72,359,102,360,306,106,99,265,115,87,
	83,297,36,307,338,135,116,103,308,241,
	254,258,257,256,255,317,319,321,320,43,
	237,92,60,22,52,122,10,294,303,86,
	355,62,30,315,313,190,111,309,114,281,
	4,146,
};
static int s390x_syscall_s2i(const char *s, int *value) {
	size_t len, i;
	len = strlen(s);
	{ char copy[len + 1];
	for (i = 0; i < len; i++) {
		char c = s[i];
		copy[i] = GT_ISUPPER(c) ? c - 'A' + 'a' : c;
	}
	copy[i] = 0;
	return s2i__(s390x_syscall_strings, s390x_syscall_s2i_s, s390x_syscall_s2i_i, 312, copy, value);
	}
}
static const unsigned s390x_syscall_i2s_direct[] = {
	371,540,1682,3031,1460,200,-1u,230,1110,2923,
	355,98,-1u,1239,104,-1u,-1u,-1u,1163,750,
	1280,2902,-1u,-1u,-1u,1630,57,-1u,1490,2972,
	-1u,-1u,16,1455,-1u,2689,1088,1793,1225,1831,
	264,1524,2875,-1u,80,-1u,-1u,2529,-1u,-1u,
	23,2909,-1u,1033,484,-1u,2383,-1u,-1u,2896,
	116,2966,268,765,742,2451,2507,-1u,-1u,-1u,
	-1u,2588,2555,2355,2441,-1u,825,872,2469,-1u,
	-1u,-1u,2671,-1u,1705,2947,2664,1731,1697,1275,
	1398,2887,598,452,-1u,773,2391,-1u,2640,574,
	-1u,2606,2731,2367,712,2635,1179,568,-1u,-1u,
	3001,901,-1u,3018,2656,2723,1061,592,2578,194,
	2306,2917,-1u,36,1286,2566,236,906,250,624,
	1673,734,445,63,2717,1512,45,-1u,-1u,-1u,
	670,2234,534,1373,1725,3037,835,490,0,1253,
	1379,1266,1387,2180,2092,2195,2107,2214,2014,2037,
	2126,1423,1366,-1u,-1u,-1u,1660,1546,1444,-1u,
	-1u,1557,1895,1837,1864,1850,1922,1879,1908,1563,
	1645,-1u,663,84,91,2517,2241,757,1637,2995,
	815,-1u,-1u,-1u,-1u,-1u,-1u,1093,885,695,
	687,679,2432,2403,702,2345,468,2422,805,2412,
	795,110,2482,2338,2329,2320,1535,1217,1185,-1u,
	-1u,1687,-1u,2489,1169,558,892,1100,500,1129,
	1139,523,1781,1150,545,865,2881,608,2148,2060,
	2742,-1u,1014,990,1001,1023,980,376,278,305,
	327,2290,397,2749,2806,2792,2775,2762,180,150,
	137,164,-1u,-1u,2647,582,1764,-1u,-1u,-1u,
	1319,1356,1343,1327,1309,1295,1070,28,1819,1081,
	3024,1050,1039,936,918,963,-1u,1483,1231,1245,
	475,614,1433,2930,1800,1115,2679,1714,459,387,
	1621,1551,2939,2274,640,2628,2694,2738,3009,-1u,
	656,315,2988,407,2978,2536,2820,338,2828,2859,
	2843,2545,346,949,1529,273,291,1569,1652,1938,
	1496,417,431,1576,1405,1465,123,2710,2377,1586,
	1603,1995,1065,510,2166,2078,1809,2226,785,1204,
	76,1975,1956,362,2954,1193,1747,2250,2599,2617,
	71,206,1122,8,854,2458,842,722,2267,2259,
	1738,1756,2498,1259,214,
};
static const char *s390x_syscall_i2s(int v) {
	return i2s_direct__(s390x_syscall_strings, s390x_syscall_i2s_direct, 1, 375, v);
}
