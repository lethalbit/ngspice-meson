
libosdi_srcs = files([
	'osdi.h',
	'osdidefs.h',
	'osdiext.h',
	'osdiinit.c',
	'osdiload.c',
	'osdiacld.c',
	'osdiparam.c',
	'osdiregistry.c',
	'osdinoise.c',
	'osdisetup.c',
	'osditrunc.c',
	'osdipzld.c',
	'osdicallbacks.c',
])

libosdi = static_library(
	'osdi',
	libosdi_srcs,
	include_directories: [ root_inc ],
	install: false,
)
