
libisrc_srcs = files([
	'isrc.c',
	'isrcacct.c',
	'isrcacld.c',
	'isrcask.c',
	'isrcdefs.h',
	'isrcdel.c',
	'isrcext.h',
	'isrcinit.c',
	'isrcinit.h',
	'isrcitf.h',
	'isrcload.c',
	'isrcpar.c',
	'isrctemp.c',
])

libisrc = static_library(
	'isrc',
	libisrc_srcs,
	include_directories: [ root_inc ],
	install: false,
)
