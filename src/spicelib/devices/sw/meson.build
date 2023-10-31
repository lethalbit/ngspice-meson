
libsw_srcs = files([
	'sw.c',
	'swacload.c',
	'swask.c',
	'swdefs.h',
	'swext.h',
	'swinit.c',
	'swinit.h',
	'switf.h',
	'swload.c',
	'swmask.c',
	'swmparam.c',
	'swnoise.c',
	'swparam.c',
	'swpzload.c',
	'swsetup.c',
	'swtrunc.c',
])

libsw = static_library(
	'sw',
	libsw_srcs,
	include_directories: [ root_inc ],
	install: false,
)
