/* This is a generated file, see Makefile.am for its inputs. */
static const char field_strings[] = "a0\0a1\0a2\0a3\0arch\0auid\0devmajor\0devminor\0dir\0egid\0"
	"euid\0exe\0exit\0field_compare\0filetype\0fsgid\0fsuid\0gid\0inode\0key\0"
	"loginuid\0msgtype\0obj_gid\0obj_lev_high\0obj_lev_low\0obj_role\0obj_type\0obj_uid\0obj_user\0path\0"
	"perm\0pers\0pid\0ppid\0sessionid\0sgid\0subj_clr\0subj_role\0subj_sen\0subj_type\0"
	"subj_user\0success\0suid\0uid";
static const unsigned field_s2i_s[] = {
	0,3,6,9,12,17,22,31,40,44,
	49,54,58,63,77,86,92,98,102,108,
	112,121,129,137,150,162,171,180,188,197,
	202,207,212,216,221,231,236,245,255,264,
	274,284,292,297,
};
static const int field_s2i_i[] = {
	200,201,202,203,11,9,100,101,107,6,
	2,112,103,111,108,8,4,5,102,210,
	9,12,110,23,22,20,21,109,19,105,
	106,10,0,18,25,7,17,14,16,15,
	13,104,3,1,
};
static int field_s2i(const char *s, int *value) {
	size_t len, i;
	len = strlen(s);
	{ char copy[len + 1];
	for (i = 0; i < len; i++) {
		char c = s[i];
		copy[i] = GT_ISUPPER(c) ? c - 'A' + 'a' : c;
	}
	copy[i] = 0;
	return s2i__(field_strings, field_s2i_s, field_s2i_i, 44, copy, value);
	}
}
static const int field_i2s_i[] = {
	0,1,2,3,4,5,6,7,8,9,
	10,11,12,13,14,15,16,17,18,19,
	20,21,22,23,25,100,101,102,103,104,
	105,106,107,108,109,110,111,112,200,201,
	202,203,210,
};
static const unsigned field_i2s_s[] = {
	212,297,49,292,92,98,44,231,86,17,
	207,12,121,274,245,264,255,236,216,188,
	162,171,150,137,221,22,31,102,58,284,
	197,202,40,77,180,129,63,54,0,3,
	6,9,108,
};
static const char *field_i2s(int v) {
	return i2s_bsearch__(field_strings, field_i2s_i, field_i2s_s, 43, v);
}
