
libsoi3_srcs = files([
	'soi3.c',
	'soi3acld.c',
	'soi3ask.c',
	'soi3cap.c',
	'soi3conv.c',
	'soi3defs.h',
	'soi3ext.h',
	'soi3ic.c',
	'soi3init.c',
	'soi3init.h',
	'soi3itf.h',
	'soi3load.c',
	'soi3mask.c',
	'soi3mpar.c',
	'soi3nois.c',
	'soi3par.c',
	'soi3set.c',
	'soi3temp.c',
	'soi3trun.c',
])

libsoi3 = static_library(
	'soi3',
	libsoi3_srcs,
	include_directories: [ root_inc ],
	install: false,
)
