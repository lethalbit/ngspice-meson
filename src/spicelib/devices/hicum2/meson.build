
libhicum2_srcs = files([
	'hicum2.c',
	'hicum2acld.c',
	'hicum2ask.c',
	'hicum2conv.c',
	'hicum2defs.h',
	'hicum2ext.h',
	'hicum2getic.c',
	'hicum2init.c',
	'hicum2init.h',
	'hicum2itf.h',
	'hicumL2.hpp',
	'hicumL2.cpp',
	'hicumL2temp.hpp',
	'hicumL2temp.cpp',
	'hicum2mask.c',
	'hicum2mpar.c',
	'hicum2noise.c',
	'hicum2param.c',
	'hicum2pzld.c',
	'hicum2setup.c',
	'hicum2soachk.c',
	'hicum2trunc.c',
])

libhicum2 = static_library(
	'hicum2',
	libhicum2_srcs,
	include_directories: [
		root_inc, cppduals_inc,
	],
	install: false,
)
