
libltra_srcs = files([
	'ltra.c',
	'ltraacct.c',
	'ltraacld.c',
	'ltraask.c',
	'ltradefs.h',
	'ltraext.h',
	'ltrainit.c',
	'ltrainit.h',
	'ltraitf.h',
	'ltraload.c',
	'ltramask.c',
	'ltramisc.c',
	'ltrampar.c',
	'ltrapar.c',
	'ltraset.c',
	'ltratemp.c',
	'ltratrun.c',
])

libltra = static_library(
	'ltra',
	libltra_srcs,
	include_directories: [ root_inc ],
	install: false,
)
