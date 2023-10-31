
libmisc_srcs = files([
	'getopt_long_bsd.c',
	'getopt_bsd.h',
	'alloc.c',
	'alloc.h',
	'dup2.c',
	'dstring.c',
	'dup2.h',
	'hash.c',
	'ivars.c',
	'ivars.h',
	'mktemp.c',
	'mktemp.h',
	'printnum.c',
	'printnum.h',
	'string.c',
	'tilde.c',
	'tilde.h',
	'misc_time.c',
	'misc_time.h',
	'wlist.c',
	'util.c',
	'util.h',
])

libmisc = static_library(
	'misc',
	libmisc_srcs,
	include_directories: [ root_inc ],
	install: false,
)
