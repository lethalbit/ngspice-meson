
libhfet2_srcs = files([
	'hfet2.c',
	'hfet2acl.c',
	'hfet2ask.c',
	'hfet2defs.h',
	'hfet2ext.h',
	'hfet2getic.c',
	'hfet2init.c',
	'hfet2init.h',
	'hfet2itf.h',
	'hfet2load.c',
	'hfet2mask.c',
	'hfet2mpar.c',
	'hfet2param.c',
	'hfet2pzl.c',
	'hfet2setup.c',
	'hfet2temp.c',
	'hfet2trunc.c',
])

libhfet2 = static_library(
	'hfet2',
	libhfet2_srcs,
	include_directories: [ root_inc ],
	install: false,
)
