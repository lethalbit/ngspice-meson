
liburc_srcs = files([
	'urc.c',
	'urcask.c',
	'urcdefs.h',
	'urcext.h',
	'urcinit.c',
	'urcinit.h',
	'urcitf.h',
	'urcmask.c',
	'urcmpar.c',
	'urcparam.c',
	'urcsetup.c',
])

liburc = static_library(
	'urc',
	liburc_srcs,
	include_directories: [ root_inc ],
	install: false,
)
