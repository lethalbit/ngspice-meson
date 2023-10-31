
libjfet2_srcs = files([
	'jfet2.c',
	'jfet2acld.c',
	'jfet2ask.c',
	'jfet2defs.h',
	'jfet2ext.h',
	'jfet2ic.c',
	'jfet2init.c',
	'jfet2init.h',
	'jfet2itf.h',
	'jfet2load.c',
	'jfet2mask.c',
	'jfet2mpar.c',
	'jfet2noi.c',
	'jfet2par.c',
	'jfet2parm.h',
	'jfet2set.c',
	'jfet2temp.c',
	'jfet2trun.c',
	'psmodel.c',
	'psmodel.h',
])

libjfet2 = static_library(
	'jfet2',
	libjfet2_srcs,
	include_directories: [ root_inc ],
	install: false,
)
