
libccvs_srcs = files([
	'ccvs.c',
	'ccvsask.c',
	'ccvsdefs.h',
	'ccvsext.h',
	'ccvsfbr.c',
	'ccvsinit.c',
	'ccvsinit.h',
	'ccvsitf.h',
	'ccvsload.c',
	'ccvspar.c',
	'ccvspzld.c',
	'ccvssacl.c',
	'ccvsset.c',
	'ccvssld.c',
	'ccvssprt.c',
	'ccvssset.c',
])

libccvs = static_library(
	'ccvs',
	libccvs_srcs,
	include_directories: [ root_inc ],
	install: false,
)
