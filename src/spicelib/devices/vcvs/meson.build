
libvcvs_srcs = files([
	'vcvs.c',
	'vcvsask.c',
	'vcvsdefs.h',
	'vcvsext.h',
	'vcvsfbr.c',
	'vcvsinit.c',
	'vcvsinit.h',
	'vcvsitf.h',
	'vcvsload.c',
	'vcvspar.c',
	'vcvspzld.c',
	'vcvssacl.c',
	'vcvsset.c',
	'vcvssld.c',
	'vcvssprt.c',
	'vcvssset.c',
])

libvcvs = static_library(
	'vcvs',
	libvcvs_srcs,
	include_directories: [ root_inc ],
	install: false,
)
