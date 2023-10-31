
libmos6_srcs = files([
	'mos6.c',
	'mos6ask.c',
	'mos6conv.c',
	'mos6defs.h',
	'mos6del.c',
	'mos6ext.h',
	'mos6ic.c',
	'mos6init.c',
	'mos6init.h',
	'mos6itf.h',
	'mos6load.c',
	'mos6mask.c',
	'mos6mpar.c',
	'mos6par.c',
	'mos6set.c',
	'mos6temp.c',
	'mos6trun.c',
])

libmos6 = static_library(
	'mos6',
	libmos6_srcs,
	include_directories: [ root_inc ],
	install: false,
)
