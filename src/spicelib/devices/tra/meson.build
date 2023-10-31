
libtra_srcs = files([
	'tra.c',
	'traacct.c',
	'traacld.c',
	'traask.c',
	'tradefs.h',
	'traext.h',
	'trainit.c',
	'trainit.h',
	'traitf.h',
	'traload.c',
	'traparam.c',
	'trasetup.c',
	'tratemp.c',
	'tratrunc.c',
])

libtra = static_library(
	'tra',
	libtra_srcs,
	include_directories: [ root_inc ],
	install: false,
)
