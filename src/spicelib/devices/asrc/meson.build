
libasrc_srcs = files([
	'asrc.c',
	'asrcacld.c',
	'asrcask.c',
	'asrcconv.c',
	'asrcdefs.h',
	'asrcdel.c',
	'asrcdest.c',
	'asrcext.h',
	'asrcfbr.c',
	'asrcitf.h',
	'asrcinit.c',
	'asrcinit.h',
	'asrcload.c',
	'asrcpar.c',
	'asrcpzld.c',
	'asrcset.c',
	'asrctemp.c',
])

libasrc = static_library(
	'asrc',
	libasrc_srcs,
	include_directories: [ root_inc ],
	install: false,
)
