
libcsw_srcs = files([
	'csw.c',
	'cswacld.c',
	'cswask.c',
	'cswdefs.h',
	'cswext.h',
	'cswinit.c',
	'cswinit.h',
	'cswitf.h',
	'cswload.c',
	'cswmask.c',
	'cswmpar.c',
	'cswnoise.c',
	'cswparam.c',
	'cswpzld.c',
	'cswsetup.c',
	'cswtrunc.c',
])

libcsw = static_library(
	'csw',
	libcsw_srcs,
	include_directories: [ root_inc ],
	install: false,
)
