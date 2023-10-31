
libpoly_srcs = files([
	'interpolate.c',
	'interpolate.h',
	'polyfit.c',
	'polyfit.h',
	'polyderiv.c',
	'polyderiv.h',
	'polyeval.c',
	'polyeval.h',
])

libpoly = static_library(
	'poly',
	libpoly_srcs,
	include_directories: [ root_inc ],
	install: false,
)
