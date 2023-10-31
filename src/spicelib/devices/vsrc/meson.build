
libvsrc_srcs = files([
	'vsrc.c',
	'vsrcacct.c',
	'vsrcacld.c',
	'vsrcask.c',
	'vsrcdefs.h',
	'vsrcdel.c',
	'vsrcext.h',
	'vsrcfbr.c',
	'vsrcinit.c',
	'vsrcinit.h',
	'vsrcitf.h',
	'vsrcload.c',
	'vsrcpar.c',
	'vsrcpzld.c',
	'vsrcpzs.c',
	'vsrcset.c',
	'vsrctemp.c',
])

libvsrc = static_library(
	'vsrc',
	libvsrc_srcs,
	include_directories: [ root_inc ],
	install: false,
)
