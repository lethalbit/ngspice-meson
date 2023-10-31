
libbsim1_srcs = files([
	'b1.c',
	'b1acld.c',
	'b1ask.c',
	'b1cvtest.c',
	'b1disto.c',
	'b1dset.c',
	'b1eval.c',
	'b1getic.c',
	'b1ld.c',
	'b1mask.c',
	'b1moscap.c',
	'b1mpar.c',
	'b1par.c',
	'b1noi.c',
	'b1pzld.c',
	'b1set.c',
	'b1temp.c',
	'b1trunc.c',
	'bsim1def.h',
	'bsim1ext.h',
	'bsim1init.c',
	'bsim1init.h',
	'bsim1itf.h',
])

libbsim1 = static_library(
	'bsim1',
	libbsim1_srcs,
	include_directories: [ root_inc ],
	install: false,
)
