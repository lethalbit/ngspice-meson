
libcpl_srcs = files([
	'cpl.c',
	'cplask.c',
	'cpldefs.h',
	'cplext.h',
	'cplinit.h',
	'cplitf.h',
	'cplmask.c',
	'cplparam.c',
	'cplload.c',
	'cplmpar.c',
	'cplsetup.c',
	'cplhash.c',
    'cplhash.h',
	'cplmdel.c',
	'cpldelete.c',
	'cplinit.c',
])

libcpl = static_library(
	'cpl',
	libcpl_srcs,
	include_directories: [ root_inc ],
	install: false,
)
