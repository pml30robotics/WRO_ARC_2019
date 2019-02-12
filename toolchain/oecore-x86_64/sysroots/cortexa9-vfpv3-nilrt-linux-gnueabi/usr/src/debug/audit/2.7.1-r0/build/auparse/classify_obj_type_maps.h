/* This is a generated file, see Makefile.am for its inputs. */
static const char classify_obj_type_map_strings[] = "account\0admin-defined-rule\0audit-config\0block-device\0character-device\0directory\0fifo\0file\0firewall\0mac-config\0"
	"printer\0process\0service\0socket\0symlink\0system\0unknown\0user-session\0virtual-machine";
static const unsigned classify_obj_type_map_i2s_direct[] = {
	156,80,53,70,40,85,141,134,118,90,
	126,0,164,177,110,149,8,27,99,
};
static const char *classify_obj_type_map_i2s(int v) {
	return i2s_direct__(classify_obj_type_map_strings, classify_obj_type_map_i2s_direct, 0, 18, v);
}
