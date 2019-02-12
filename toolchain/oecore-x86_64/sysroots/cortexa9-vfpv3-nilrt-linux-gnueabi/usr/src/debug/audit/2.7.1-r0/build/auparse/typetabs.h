/* This is a generated file, see Makefile.am for its inputs. */
static const char type_strings[] = "a0\0a1\0a2\0a3\0acct\0action\0addr\0arch\0auid\0cap_fi\0"
	"cap_fp\0cap_pe\0cap_pi\0cap_pp\0capability\0cgroup\0cmd\0code\0comm\0cwd\0"
	"data\0device\0dir\0egid\0euid\0exe\0exit\0family\0fe\0fi\0"
	"file\0flags\0fp\0fsgid\0fsuid\0gid\0grp\0hook\0icmptype\0id\0"
	"igid\0img-ctx\0inode_gid\0inode_uid\0invalid_context\0ioctlcmd\0iuid\0key\0list\0macproto\0"
	"mode\0name\0new-chardev\0new-disk\0new-fs\0new-net\0new-rng\0new_gid\0new_group\0new_pe\0"
	"new_pi\0new_pp\0oauid\0obj\0obj_gid\0obj_uid\0ocomm\0oflag\0ogid\0old-auid\0"
	"old-chardev\0old-disk\0old-fs\0old-net\0old-rng\0old_pe\0old_pi\0old_pp\0old_prom\0ouid\0"
	"path\0per\0perm\0perm_mask\0proctitle\0prom\0proto\0res\0result\0saddr\0"
	"sauid\0scontext\0ses\0sgid\0sig\0sigev_signo\0subj\0suid\0syscall\0tcontext\0"
	"uid\0vm\0vm-ctx\0watch";
static const unsigned type_s2i_s[] = {
	0,3,6,9,12,17,24,29,34,39,
	46,53,60,67,74,85,92,96,101,106,
	110,115,122,126,131,136,140,145,152,155,
	158,163,169,172,178,184,188,192,197,206,
	209,214,222,232,242,258,267,272,276,281,
	290,295,300,312,321,328,336,344,352,362,
	369,376,383,389,393,401,409,415,421,426,
	435,447,456,463,471,479,486,493,500,509,
	514,519,523,528,538,548,553,559,563,570,
	576,582,591,595,600,604,616,621,626,634,
	643,647,650,657,
};
static const int type_s2i_i[] = {
	14,15,16,17,6,35,26,4,1,22,
	22,22,22,22,12,6,6,28,6,6,
	20,6,6,2,1,6,5,23,22,22,
	6,30,22,2,1,2,6,34,24,1,
	2,32,2,1,6,37,1,38,19,36,
	8,6,6,6,6,6,6,2,6,22,
	22,22,1,32,2,1,6,29,2,1,
	6,6,6,6,6,22,22,22,11,1,
	6,27,7,7,33,11,25,13,13,9,
	1,32,21,2,18,18,32,1,3,32,
	1,6,32,6,
};
static int type_s2i(const char *s, int *value) {
	return s2i__(type_strings, type_s2i_s, type_s2i_i, 104, s, value);
}
