
libtxl_srcs = files([
	'txl.c',
	'txlacct.c',
	'txlask.c',
	'txldefs.h',
	'txlext.h',
	'txlfbr.c',
	'txlinit.h',
	'txlitf.h',
	'txlload.c',
	'txlparam.c',
	'txlmask.c',
	'txlmpar.c',
	'txlsetup.c',
	'txlinit.c'
])

libtxl = static_library(
	'txl',
	libtxl_srcs,
	include_directories: [ root_inc ],
	install: false,
)
