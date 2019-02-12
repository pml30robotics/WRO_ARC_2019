/* This is a generated file, see Makefile.am for its inputs. */
static const char ia64_syscall_strings[] = "_sysctl\0accept\0accept4\0access\0acct\0add_key\0adjtimex\0afs_syscall\0bdflush\0bind\0"
	"bpf\0brk\0capget\0capset\0chdir\0chmod\0chown\0chroot\0clock_adjtime\0clock_getres\0"
	"clock_gettime\0clock_nanosleep\0clock_settime\0clone\0clone2\0close\0connect\0copy_file_range\0creat\0delete_module\0"
	"dup\0dup2\0dup3\0epoll_create\0epoll_create1\0epoll_ctl\0epoll_pwait\0epoll_wait\0eventfd\0eventfd2\0"
	"execve\0execveat\0exit\0exit_group\0faccessat\0fadvise64\0fallocate\0fanotify_init\0fanotify_mark\0fchdir\0"
	"fchmod\0fchmodat\0fchown\0fchownat\0fcntl\0fdatasync\0fgetxattr\0finit_module\0flistxattr\0flock\0"
	"fremovexattr\0fsetxattr\0fstat\0fstatfs\0fstatfs64\0fsync\0ftruncate\0futex\0futimesat\0get_mempolicy\0"
	"get_robust_list\0getcpu\0getcwd\0getdents\0getdents64\0getegid\0geteuid\0getgid\0getgroups\0getitimer\0"
	"getpeername\0getpgid\0getpid\0getpmsg\0getppid\0getpriority\0getrandom\0getresgid\0getresuid\0getrlimit\0"
	"getrusage\0getsid\0getsockname\0getsockopt\0gettid\0gettimeofday\0getuid\0getunwind\0getxattr\0init_module\0"
	"inotify_add_watch\0inotify_init\0inotify_init1\0inotify_rm_watch\0io_cancel\0io_destroy\0io_getevents\0io_setup\0io_submit\0ioctl\0"
	"ioprio_get\0ioprio_set\0kcmp\0kexec_load\0keyctl\0kill\0lchown\0lgetxattr\0link\0linkat\0"
	"listen\0listxattr\0llistxattr\0lookup_dcookie\0lremovexattr\0lseek\0lsetxattr\0lstat\0madvise\0mbind\0"
	"membarrier\0memfd_create\0migrate_pages\0mincore\0mkdir\0mkdirat\0mknod\0mknodat\0mlock\0mlock2\0"
	"mlockall\0mmap\0mmap2\0mount\0mprotect\0mq_getsetattr\0mq_notify\0mq_open\0mq_timedreceive\0mq_timedsend\0"
	"mq_unlink\0mremap\0msgctl\0msgget\0msgrcv\0msgsnd\0msync\0munlock\0munlockall\0munmap\0"
	"name_to_handle_at\0nanosleep\0newfstatat\0nfsservctl\0ni_syscall\0open\0open_by_handle_at\0openat\0pciconfig_read\0pciconfig_write\0"
	"perfmonctl\0personality\0pipe\0pipe2\0pivot_root\0poll\0ppoll\0prctl\0pread64\0preadv\0"
	"prlimit64\0process_vm_readv\0process_vm_writev\0pselect\0ptrace\0putpmsg\0pwrite64\0pwritev\0quotactl\0read\0"
	"readahead\0readlink\0readlinkat\0readv\0reboot\0recv\0recvfrom\0recvmmsg\0recvmsg\0remap_file_pages\0"
	"removexattr\0rename\0renameat\0renameat2\0request_key\0restart_syscall\0rmdir\0rt_sigaction\0rt_sigpending\0rt_sigprocmask\0"
	"rt_sigqueueinfo\0rt_sigreturn\0rt_sigsuspend\0rt_sigtimedwait\0rt_tgsigqueueinfo\0sched_get_priority_max\0sched_get_priority_min\0sched_getaffinity\0sched_getattr\0sched_getparam\0"
	"sched_getscheduler\0sched_rr_get_interval\0sched_setaffinity\0sched_setattr\0sched_setparam\0sched_setscheduler\0sched_yield\0select\0semctl\0semget\0"
	"semop\0semtimedop\0send\0sendfile\0sendmmsg\0sendmsg\0sendto\0set_mempolicy\0set_robust_list\0set_tid_address\0"
	"set_zone_reclaim\0setdomainname\0setfsgid\0setfsuid\0setgid\0setgroups\0sethostname\0setitimer\0setns\0setpgid\0"
	"setpriority\0setregid\0setresgid\0setresuid\0setreuid\0setrlimit\0setsid\0setsockopt\0settimeofday\0setuid\0"
	"setxattr\0shmat\0shmctl\0shmdt\0shmget\0shutdown\0sigaltstack\0signalfd\0signalfd4\0socket\0"
	"socketpair\0splice\0stat\0statfs\0statfs64\0swapoff\0swapon\0symlink\0symlinkat\0sync\0"
	"sync_file_range\0syncfs\0sysfs\0sysinfo\0syslog\0tee\0tgkill\0timer_create\0timer_delete\0timer_getoverrun\0"
	"timer_gettime\0timer_settime\0timerfd\0timerfd_create\0timerfd_gettime\0timerfd_settime\0times\0tkill\0truncate\0tux\0"
	"umask\0umount\0uname\0unlink\0unlinkat\0unshare\0uselib\0userfaultfd\0ustat\0utimensat\0"
	"utimes\0vhangup\0vmsplice\0vserver\0wait4\0waitid\0write\0writev";
static const unsigned ia64_syscall_s2i_s[] = {
	0,8,15,23,30,35,43,52,64,72,
	77,81,85,92,99,105,111,117,124,138,
	151,165,181,195,201,208,214,222,238,244,
	258,262,267,272,285,299,309,321,332,340,
	349,356,365,370,381,391,401,411,425,439,
	446,453,462,469,478,484,494,504,517,528,
	534,547,557,563,571,581,587,597,603,613,
	627,643,650,657,666,677,685,693,700,710,
	720,732,740,747,755,763,775,785,795,805,
	815,825,832,844,855,862,875,882,892,901,
	913,931,944,958,975,985,996,1009,1018,1028,
	1034,1045,1056,1061,1072,1079,1084,1091,1101,1106,
	1113,1120,1130,1141,1156,1169,1175,1185,1191,1199,
	1205,1216,1229,1243,1251,1257,1265,1271,1279,1285,
	1292,1301,1306,1312,1318,1327,1341,1351,1359,1375,
	1388,1398,1405,1412,1419,1426,1433,1439,1447,1458,
	1465,1483,1493,1504,1515,1526,1531,1549,1556,1571,
	1587,1598,1610,1615,1621,1632,1637,1643,1649,1657,
	1664,1674,1691,1709,1717,1724,1732,1741,1749,1758,
	1763,1773,1782,1793,1799,1806,1811,1820,1829,1837,
	1854,1866,1873,1882,1892,1904,1920,1926,1939,1953,
	1968,1984,1997,2011,2027,2045,2068,2091,2109,2123,
	2138,2157,2179,2197,2211,2226,2245,2257,2264,2271,
	2278,2284,2295,2300,2309,2318,2326,2333,2347,2363,
	2379,2396,2410,2419,2428,2435,2445,2457,2467,2473,
	2481,2493,2502,2512,2522,2531,2541,2548,2559,2572,
	2579,2588,2594,2601,2607,2614,2623,2635,2644,2654,
	2661,2672,2679,2684,2691,2700,2708,2715,2723,2733,
	2738,2754,2761,2767,2775,2782,2786,2793,2806,2819,
	2836,2850,2864,2872,2887,2903,2919,2925,2931,2940,
	2944,2950,2957,2963,2970,2979,2987,2994,3006,3012,
	3022,3029,3037,3046,3054,3060,3067,3073,
};
static const int ia64_syscall_s2i_i[] = {
	1150,1194,1334,1049,1064,1271,1131,1141,1138,1191,
	1341,1060,1185,1186,1034,1038,1039,1068,1328,1255,
	1254,1256,1253,1128,1213,1029,1192,1347,1030,1134,
	1057,1070,1316,1243,1315,1244,1305,1245,1309,1314,
	1033,1342,1025,1236,1293,1234,1303,1323,1324,1035,
	1099,1292,1100,1284,1066,1052,1222,1335,1225,1145,
	1228,1219,1212,1104,1257,1051,1098,1230,1285,1260,
	1299,1304,1184,1144,1214,1063,1047,1062,1077,1119,
	1196,1079,1041,1188,1042,1101,1339,1075,1073,1085,
	1086,1082,1195,1204,1105,1087,1046,1215,1220,1133,
	1278,1277,1318,1279,1242,1239,1240,1238,1241,1065,
	1275,1274,1345,1268,1273,1053,1124,1221,1031,1289,
	1193,1223,1224,1237,1227,1040,1218,1211,1209,1259,
	1344,1340,1280,1208,1055,1282,1037,1283,1153,1346,
	1154,1151,1172,1043,1155,1267,1266,1262,1265,1264,
	1263,1156,1112,1109,1111,1110,1157,1158,1159,1152,
	1326,1168,1286,1169,1024,1028,1327,1281,1173,1174,
	1175,1140,1058,1317,1207,1090,1295,1170,1148,1319,
	1325,1332,1333,1294,1048,1189,1149,1320,1137,1026,
	1216,1092,1291,1146,1096,1200,1201,1322,1206,1125,
	1226,1054,1288,1338,1272,1246,1056,1177,1178,1179,
	1180,1181,1182,1183,1321,1165,1166,1232,1337,1160,
	1162,1167,1231,1336,1161,1163,1164,1089,1108,1106,
	1107,1247,1198,1187,1331,1205,1199,1261,1298,1233,
	1276,1129,1143,1142,1061,1078,1083,1118,1330,1080,
	1102,1072,1076,1074,1071,1084,1081,1203,1088,1045,
	1217,1114,1116,1115,1113,1202,1176,1307,1313,1190,
	1197,1297,1210,1103,1258,1095,1094,1091,1290,1050,
	1300,1329,1139,1127,1117,1301,1235,1248,1252,1251,
	1250,1249,1308,1310,1312,1311,1059,1229,1097,1120,
	1067,1044,1130,1032,1287,1296,1093,1343,1069,1306,
	1036,1123,1302,1269,1126,1270,1027,1147,
};
static int ia64_syscall_s2i(const char *s, int *value) {
	size_t len, i;
	len = strlen(s);
	{ char copy[len + 1];
	for (i = 0; i < len; i++) {
		char c = s[i];
		copy[i] = GT_ISUPPER(c) ? c - 'A' + 'a' : c;
	}
	copy[i] = 0;
	return s2i__(ia64_syscall_strings, ia64_syscall_s2i_s, ia64_syscall_s2i_i, 318, copy, value);
	}
}
static const unsigned ia64_syscall_i2s_direct[] = {
	1515,365,1758,3067,1526,208,238,1101,2963,349,
	99,439,3022,1265,105,111,1169,740,755,1312,
	2950,2572,875,685,1717,23,2733,581,484,1079,
	1866,1251,1920,258,1610,2919,81,2428,693,677,
	30,1028,478,2944,117,3006,262,2522,2493,795,
	2512,785,2502,700,2435,732,2473,2541,825,2445,
	2531,805,815,862,2559,2257,1632,2715,1773,2987,
	2708,2700,1799,2931,587,446,462,763,2481,2684,
	563,855,2271,2278,2264,1412,1426,1419,1405,2607,
	2588,2601,2594,2775,2457,710,2940,-1u,-1u,3029,
	1084,1837,3054,2767,195,2396,2957,43,-1u,901,
	244,-1u,-1u,1749,64,2761,1598,52,2419,2410,
	657,528,1793,3073,1649,1732,0,1301,1458,1279,
	1292,1318,1398,1433,1439,1447,2123,2211,2138,2226,
	2245,2045,2068,2157,1483,1504,1643,-1u,1306,1556,
	1571,1587,2623,1926,1939,1953,1968,1984,1997,2011,
	650,85,92,2300,747,1724,2654,72,214,1113,
	8,832,720,2661,2295,2326,1806,1811,2614,2548,
	844,2318,1829,1621,1243,1191,2679,1185,557,201,
	666,882,1763,2579,1175,547,892,1091,494,1120,
	1130,517,1854,1156,534,2925,597,2179,2091,2363,
	391,2786,370,1141,1009,985,996,1018,975,272,
	299,321,1904,2284,2793,2850,2836,2819,2806,181,
	151,138,165,571,2691,1199,613,2333,1351,1388,
	1375,1359,1341,1327,1061,3046,3060,35,1892,1072,
	1045,1034,2379,931,913,958,1229,1549,1257,1271,
	469,603,1493,2970,1873,1106,2723,1782,453,381,
	1709,1637,2979,2672,2347,627,2738,2782,3037,401,
	643,309,3012,2635,2864,332,2872,2903,2887,2644,
	340,285,267,1615,944,1657,1741,2027,1820,411,
	425,1664,1465,1531,124,2754,2467,2309,1674,1691,
	15,504,2197,2109,1882,775,1216,77,356,2994,
	1205,1056,1285,222,
};
static const char *ia64_syscall_i2s(int v) {
	return i2s_direct__(ia64_syscall_strings, ia64_syscall_i2s_direct, 1024, 1347, v);
}
