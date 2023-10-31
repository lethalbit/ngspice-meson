
libres_srcs = files([
	'res.c',
	'resask.c',
	'resdefs.h',
	'resext.h',
	'resinit.c',
	'resinit.h',
	'resitf.h',
	'resload.c',
	'resmask.c',
	'resmpar.c',
	'resnoise.c',
	'resparam.c',
	'respzld.c',
	'ressacl.c',
	'ressetup.c',
	'ressoachk.c',
	'ressload.c',
	'ressprt.c',
	'ressset.c',
	'restemp.c',
])

libres = static_library(
	'res',
	libres_srcs,
	include_directories: [ root_inc ],
	install: false,
)
