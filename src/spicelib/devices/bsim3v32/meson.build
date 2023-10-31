
libbsim3v32_srcs = files([
	'b3v32.c',
	'b3v32acld.c',
	'b3v32ask.c',
	'b3v32check.c',
	'b3v32cvtest.c',
	'b3v32getic.c',
	'b3v32ld.c',
	'b3v32mask.c',
	'b3v32mdel.c',
	'b3v32mpar.c',
	'b3v32noi.c',
	'b3v32par.c',
	'b3v32pzld.c',
	'b3v32set.c',
	'b3v32soachk.c',
	'b3v32temp.c',
	'b3v32trunc.c',
	'bsim3v32def.h',
	'bsim3v32ext.h',
	'bsim3v32init.c',
	'bsim3v32init.h',
	'bsim3v32itf.h',
])

libbsim3v32 = static_library(
	'bsim3v32',
	libbsim3v32_srcs,
	include_directories: [ root_inc ],
	install: false,
)
