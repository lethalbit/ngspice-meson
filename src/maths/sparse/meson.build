
libsparse_srcs = files([
	'spalloc.c',
	'spbuild.c',
	'spconfig.h',
	'spdefs.h',
	'spextra.c',
	'spfactor.c',
	'spoutput.c',
	'spsmp.c',
	'spsolve.c',
	'sputils.c',
])

libsparse = static_library(
	'sparse',
	libsparse_srcs,
	include_directories: [ root_inc ],
	install: false,
)
