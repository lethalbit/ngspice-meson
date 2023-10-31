
libvccs_srcs = files([
	'vccs.c',
	'vccsask.c',
	'vccsdefs.h',
	'vccsext.h',
	'vccsinit.c',
	'vccsinit.h',
	'vccsitf.h',
	'vccsload.c',
	'vccspar.c',
	'vccspzld.c',
	'vccssacl.c',
	'vccsset.c',
	'vccssld.c',
	'vccssprt.c',
	'vccssset.c',
])

libvccs = static_library(
	'vccs',
	libvccs_srcs,
	include_directories: [ root_inc ],
	install: false,
)
