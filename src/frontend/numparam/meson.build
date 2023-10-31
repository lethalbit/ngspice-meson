
libnumparam_srcs = files([
	'spicenum.c',
	'xpressn.c',
	'mystring.c',
	'general.h',
	'numpaif.h',
	'numparam.h',
])

libnumparam = static_library(
	'numparam',
	libnumparam_srcs,
	include_directories: [ root_inc ],
	install: false,
)
