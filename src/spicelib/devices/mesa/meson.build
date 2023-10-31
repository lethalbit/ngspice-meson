
libmesa_srcs = files([
	'mesa.c',
	'mesaacl.c',
	'mesaask.c',
	'mesadefs.h',
	'mesaext.h',
	'mesagetic.c',
	'mesainit.c',
	'mesainit.h',
	'mesaitf.h',
	'mesaload.c',
	'mesamask.c',
	'mesamparam.c',
	'mesaparam.c',
	'mesapzl.c',
	'mesasetup.c',
	'mesatemp.c',
	'mesatrunc.c',

])

libmesa = static_library(
	'mesa',
	libmesa_srcs,
	include_directories: [ root_inc ],
	install: false,
)
