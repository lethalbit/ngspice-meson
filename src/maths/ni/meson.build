
libni_srcs = files([
	'niaciter.c',
	'nicomcof.c',
	'niconv.c',
	'nidest.c',
	'niditer.c',
	'niinit.c',
	'niinteg.c',
	'niiter.c',
	'niniter.c',
	'nipred.c',
	'nipzmeth.c',
	'nireinit.c',
	'nisenre.c',
])

libni = static_library(
	'ni',
	libni_srcs,
	include_directories: [ root_inc ],
	install: false,
)
