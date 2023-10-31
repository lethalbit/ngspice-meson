
libbsim3v1_srcs = files([
	'b3v1.c',
	'b3v1acld.c',
	'b3v1ask.c',
	'b3v1check.c',
	'b3v1cvtest.c',
	'b3v1getic.c',
	'b3v1ld.c',
	'b3v1mask.c',
	'b3v1mpar.c',
	'b3v1noi.c',
	'b3v1par.c',
	'b3v1pzld.c',
	'b3v1set.c',
	'b3v1temp.c',
	'b3v1trunc.c',
	'bsim3v1def.h',
	'bsim3v1ext.h',
	'bsim3v1init.c',
	'bsim3v1init.h',
	'bsim3v1itf.h',
])

libbsim3v1 = static_library(
	'bsim3v1',
	libbsim3v1_srcs,
	include_directories: [ root_inc ],
	install: false,
)
