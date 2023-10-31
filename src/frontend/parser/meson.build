
libparser_srcs = files([
	'backq.c',
	'backq.h',
	'complete.c',
	'complete.h',
	'cshpar.c',
	'cshpar.h',
	'glob.c',
	'glob.h',
	'input.c',
	'input.h',
	'lexical.c',
	'lexical.h',
	'numparse.c',
	'numparse.h',
	'std.c',
	'unixcom.c',
	'unixcom.h',
])

libparser = static_library(
	'parser',
	libparser_srcs,
	include_directories: [ root_inc ],
	install: false,
)
