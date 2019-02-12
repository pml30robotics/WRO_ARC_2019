/* This is a generated file, see Makefile.am for its inputs. */
static const char classify_record_map_strings[] = "aborted-auditd-startup\0access-error\0access-permission\0access-result\0acquired-credentials\0added-group-account-to\0added-user-account\0assigned-user-role-to\0assigned-vm-id\0assigned-vm-resource\0"
	"audit-error\0authenticated\0authenticated-to-group\0booted-system\0changed-audit-configuration\0changed-audit-feature\0changed-auditd-configuration\0changed-configuration\0changed-group\0changed-group-password\0"
	"changed-login-id-to\0changed-mac-configuration\0changed-password\0changed-role-to\0changed-selinux-boolean\0changed-selinux-enforcement\0changed-to-runlevel\0changed-user-id\0crashed-program\0crypto-officer-logged-in\0"
	"crypto-officer-logged-out\0deleted-group-account-from\0deleted-user-account\0disposed-credentials\0ended-session\0error\0initialized-audit-subsystem\0issued-vm-control\0loaded-mac-policy\0loaded-selinux-policy\0"
	"locked-account\0logged-in\0logged-out\0mac-permission\0modified-group-account\0modified-level-of\0modified-role\0modified-user-account\0negotiated-crypto-key\0overrode-label-of\0"
	"ran-command\0reconfigured-auditd\0refreshed-credentials\0relabeled-filesystem\0remote-audit-connected\0remote-audit-disconnected\0removed-use-role-from\0resumed-audit-logging\0rotated-audit-logs\0sent-message\0"
	"sent-test\0shutdown-audit\0shutdown-system\0started-audit\0started-crypto-session\0started-service\0started-session\0stopped-service\0typed\0unknown\0"
	"unlocked-account\0use-suspcious-link\0violated-seccomp-policy\0violated-selinux-policy\0was-authorized";
static const int classify_record_map_i2s_i[] = {
	1005,1006,1100,1101,1102,1103,1104,1105,1106,1107,
	1108,1109,1110,1111,1112,1113,1114,1115,1116,1117,
	1118,1119,1120,1121,1122,1123,1124,1125,1126,1127,
	1128,1129,1130,1131,1132,1133,1134,1135,1136,1200,
	1201,1202,1203,1204,1205,1206,1207,1208,1209,1305,
	1326,1328,1400,1403,1404,1405,1701,1702,2000,2300,
	2301,2302,2303,2304,2309,2310,2311,2312,2402,2403,
	2404,2407,2500,2501,2502,
};
static const unsigned classify_record_map_i2s_s[] = {
	1154,390,201,1391,905,68,672,1261,693,36,
	436,707,999,331,814,824,112,651,89,624,
	54,353,1167,1299,23,967,1293,541,215,238,
	1192,521,1245,1277,850,367,835,799,1307,1208,
	1177,0,302,979,1135,1113,1042,1065,189,252,
	1343,280,1367,777,493,469,557,1324,713,453,
	131,1091,949,873,1021,759,891,410,573,598,
	927,1222,741,168,153,
};
static const char *classify_record_map_i2s(int v) {
	return i2s_bsearch__(classify_record_map_strings, classify_record_map_i2s_i, classify_record_map_i2s_s, 75, v);
}
