
libcccs_srcs = files([
	'cccs.c',
	'cccsask.c',
	'cccsdefs.h',
	'cccsext.h',
	'cccsinit.c',
	'cccsinit.h',
	'cccsitf.h',
	'cccsload.c',
	'cccspar.c',
	'cccspzld.c',
	'cccssacl.c',
	'cccsset.c',
	'cccssld.c',
	'cccssprt.c',
	'cccssset.c',
])

libcccs = static_library(
	'cccs',
	libcccs_srcs,
	include_directories: [ root_inc ],
	install: false,
)
