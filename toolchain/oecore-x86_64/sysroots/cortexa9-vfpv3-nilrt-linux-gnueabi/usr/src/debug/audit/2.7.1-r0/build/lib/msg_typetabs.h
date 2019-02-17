/* This is a generated file, see Makefile.am for its inputs. */
static const char msg_type_strings[] = "ACCT_LOCK\0ACCT_UNLOCK\0ADD_GROUP\0ADD_USER\0ANOM_ABEND\0ANOM_ACCESS_FS\0ANOM_ADD_ACCT\0ANOM_AMTU_FAIL\0ANOM_CRYPTO_FAIL\0ANOM_DEL_ACCT\0"
	"ANOM_EXEC\0ANOM_LINK\0ANOM_LOGIN_ACCT\0ANOM_LOGIN_FAILURES\0ANOM_LOGIN_LOCATION\0ANOM_LOGIN_SESSIONS\0ANOM_LOGIN_TIME\0ANOM_MAX_DAC\0ANOM_MAX_MAC\0ANOM_MK_EXEC\0"
	"ANOM_MOD_ACCT\0ANOM_PROMISCUOUS\0ANOM_RBAC_FAIL\0ANOM_RBAC_INTEGRITY_FAIL\0ANOM_ROOT_TRANS\0AVC\0AVC_PATH\0BPRM_FCAPS\0CAPSET\0CHGRP_ID\0"
	"CHUSER_ID\0CONFIG_CHANGE\0CRED_ACQ\0CRED_DISP\0CRED_REFR\0CRYPTO_FAILURE_USER\0CRYPTO_IKE_SA\0CRYPTO_IPSEC_SA\0CRYPTO_KEY_USER\0CRYPTO_LOGIN\0"
	"CRYPTO_LOGOUT\0CRYPTO_PARAM_CHANGE_USER\0CRYPTO_REPLAY_USER\0CRYPTO_SESSION\0CRYPTO_TEST_USER\0CWD\0DAC_CHECK\0DAEMON_ABORT\0DAEMON_ACCEPT\0DAEMON_CLOSE\0"
	"DAEMON_CONFIG\0DAEMON_END\0DAEMON_ERR\0DAEMON_RESUME\0DAEMON_ROTATE\0DAEMON_START\0DEL_GROUP\0DEL_USER\0DEV_ALLOC\0DEV_DEALLOC\0"
	"EOE\0EXECVE\0FD_PAIR\0FEATURE_CHANGE\0FS_RELABEL\0GRP_AUTH\0GRP_CHAUTHTOK\0GRP_MGMT\0INTEGRITY_DATA\0INTEGRITY_HASH\0"
	"INTEGRITY_METADATA\0INTEGRITY_PCR\0INTEGRITY_RULE\0INTEGRITY_STATUS\0IPC\0IPC_SET_PERM\0KERNEL\0KERNEL_OTHER\0LABEL_LEVEL_CHANGE\0LABEL_OVERRIDE\0"
	"LOGIN\0MAC_CHECK\0MAC_CIPSOV4_ADD\0MAC_CIPSOV4_DEL\0MAC_CONFIG_CHANGE\0MAC_IPSEC_ADDSA\0MAC_IPSEC_ADDSPD\0MAC_IPSEC_DELSA\0MAC_IPSEC_DELSPD\0MAC_IPSEC_EVENT\0"
	"MAC_MAP_ADD\0MAC_MAP_DEL\0MAC_POLICY_LOAD\0MAC_STATUS\0MAC_UNLBL_ALLOW\0MAC_UNLBL_STCADD\0MAC_UNLBL_STCDEL\0MMAP\0MQ_GETSETATTR\0MQ_NOTIFY\0"
	"MQ_OPEN\0MQ_SENDRECV\0NETFILTER_CFG\0NETFILTER_PKT\0OBJ_PID\0PATH\0PROCTITLE\0RESP_ACCT_LOCK\0RESP_ACCT_LOCK_TIMED\0RESP_ACCT_REMOTE\0"
	"RESP_ACCT_UNLOCK_TIMED\0RESP_ALERT\0RESP_ANOMALY\0RESP_EXEC\0RESP_HALT\0RESP_KILL_PROC\0RESP_SEBOOL\0RESP_SINGLE\0RESP_TERM_ACCESS\0RESP_TERM_LOCK\0"
	"ROLE_ASSIGN\0ROLE_MODIFY\0ROLE_REMOVE\0SECCOMP\0SELINUX_ERR\0SERVICE_START\0SERVICE_STOP\0SOCKADDR\0SOCKETCALL\0SYSCALL\0"
	"SYSTEM_BOOT\0SYSTEM_RUNLEVEL\0SYSTEM_SHUTDOWN\0TEST\0TRUSTED_APP\0TTY\0USER\0USER_ACCT\0USER_AUTH\0USER_AVC\0"
	"USER_CHAUTHTOK\0USER_CMD\0USER_END\0USER_ERR\0USER_LABELED_EXPORT\0USER_LOGIN\0USER_LOGOUT\0USER_MAC_CONFIG_CHANGE\0USER_MAC_POLICY_LOAD\0USER_MGMT\0"
	"USER_ROLE_CHANGE\0USER_SELINUX_ERR\0USER_START\0USER_TTY\0USER_UNLABELED_EXPORT\0USYS_CONFIG\0VIRT_CONTROL\0VIRT_MACHINE_ID\0VIRT_RESOURCE";
static const unsigned msg_type_s2i_s[] = {
	0,10,22,32,41,52,67,81,96,113,
	127,137,147,163,183,203,223,239,252,265,
	278,292,309,324,349,365,369,378,389,396,
	405,415,429,438,448,458,478,492,508,524,
	537,551,576,595,610,627,631,641,654,668,
	681,695,706,717,731,745,758,768,777,787,
	799,803,810,818,833,844,853,867,876,891,
	906,925,939,954,971,975,988,995,1008,1027,
	1042,1048,1058,1074,1090,1108,1124,1141,1157,1174,
	1190,1202,1214,1230,1241,1257,1274,1291,1296,1310,
	1320,1328,1340,1354,1368,1376,1381,1391,1406,1427,
	1444,1467,1478,1491,1501,1511,1526,1538,1550,1567,
	1582,1594,1606,1618,1626,1638,1652,1665,1674,1685,
	1693,1705,1721,1737,1742,1754,1758,1763,1773,1783,
	1792,1807,1816,1825,1834,1854,1865,1877,1900,1921,
	1931,1948,1965,1976,1985,2007,2019,2032,2048,
};
static const int msg_type_s2i_i[] = {
	1135,1136,1116,1114,1701,2111,2114,2107,2110,2115,
	2112,1702,2103,2100,2104,2102,2101,2105,2106,2113,
	2116,1700,2108,2109,2117,1400,1402,1321,1322,1119,
	1125,1305,1103,1104,1110,2405,2408,2409,2404,2402,
	2403,2401,2406,2407,2400,1307,1118,1202,1207,1208,
	1203,1201,1209,1206,1205,1200,1117,1115,2307,2308,
	1320,1309,1317,1328,2309,1126,1133,1132,1800,1803,
	1801,1804,1805,1802,1303,1311,2000,1316,2304,2303,
	1006,1134,1407,1408,1405,1411,1413,1412,1414,1415,
	1409,1410,1403,1404,1406,1416,1417,1323,1315,1314,
	1312,1313,1325,1324,1318,1302,1327,2207,2205,2204,
	2206,2201,2200,2210,2212,2202,2209,2211,2203,2208,
	2301,2311,2302,1326,1401,1130,1131,1306,1304,1300,
	1127,1129,1128,1120,1121,1319,1005,1101,1100,1107,
	1108,1123,1106,1109,2305,1112,1113,2312,2310,1102,
	2300,1122,1105,1124,2306,1111,2500,2502,2501,
};
static int msg_type_s2i(const char *s, int *value) {
	size_t len, i;
	len = strlen(s);
	{ char copy[len + 1];
	for (i = 0; i < len; i++) {
		char c = s[i];
		copy[i] = GT_ISLOWER(c) ? c - 'a' + 'A' : c;
	}
	copy[i] = 0;
	return s2i__(msg_type_strings, msg_type_s2i_s, msg_type_s2i_i, 159, copy, value);
	}
}
static const int msg_type_i2s_i[] = {
	1005,1006,1100,1101,1102,1103,1104,1105,1106,1107,
	1108,1109,1110,1111,1112,1113,1114,1115,1116,1117,
	1118,1119,1120,1121,1122,1123,1124,1125,1126,1127,
	1128,1129,1130,1131,1132,1133,1134,1135,1136,1200,
	1201,1202,1203,1205,1206,1207,1208,1209,1300,1302,
	1303,1304,1305,1306,1307,1309,1311,1312,1313,1314,
	1315,1316,1317,1318,1319,1320,1321,1322,1323,1324,
	1325,1326,1327,1328,1400,1401,1402,1403,1404,1405,
	1406,1407,1408,1409,1410,1411,1412,1413,1414,1415,
	1416,1417,1700,1701,1702,1800,1801,1802,1803,1804,
	1805,2000,2100,2101,2102,2103,2104,2105,2106,2107,
	2108,2109,2110,2111,2112,2113,2114,2115,2116,2117,
	2200,2201,2202,2203,2204,2205,2206,2207,2208,2209,
	2210,2211,2212,2300,2301,2302,2303,2304,2305,2306,
	2307,2308,2309,2310,2311,2312,2400,2401,2402,2403,
	2404,2405,2406,2407,2408,2409,2500,2501,2502,
};
static const unsigned msg_type_i2s_s[] = {
	1758,1042,1773,1763,1921,429,438,1965,1816,1783,
	1792,1825,448,2007,1854,1865,32,768,22,758,
	631,396,1737,1742,1948,1807,1976,405,844,1693,
	1721,1705,1638,1652,867,853,1048,0,10,745,
	695,641,681,731,717,654,668,706,1685,1376,
	971,1674,415,1665,627,803,975,1320,1328,1310,
	1296,995,810,1368,1754,799,378,389,1291,1354,
	1340,1618,1381,818,365,1626,369,1214,1230,1090,
	1241,1058,1074,1190,1202,1108,1141,1124,1157,1174,
	1257,1274,292,41,137,876,906,954,891,925,
	939,988,163,223,203,147,183,239,252,81,
	309,324,96,52,127,265,67,113,278,349,
	1478,1467,1511,1550,1427,1406,1444,1391,1567,1526,
	1491,1538,1501,1931,1582,1606,1027,1008,1834,1985,
	777,787,833,1900,1594,1877,610,551,524,537,
	508,458,576,595,478,492,2019,2048,2032,
};
static const char *msg_type_i2s(int v) {
	return i2s_bsearch__(msg_type_strings, msg_type_i2s_i, msg_type_i2s_s, 159, v);
}