
libcidersuprt_srcs = files([
	'database.c',
	'devprint.c',
	'geominfo.c',
	'globals.c',
	'integset.c',
	'integuse.c',
	'logfile.c',
	'mater.c',
	'misc.c',
	'mobil.c',
	'recomb.c',
	'suprem.c',
	'suprmitf.c',
])

libcidersuprt = static_library(
	'cidersuprt',
	libcidersuprt_srcs,
	include_directories: [ root_inc ],
	install: false,
)
