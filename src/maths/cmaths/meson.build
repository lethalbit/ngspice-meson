
libcmaths_srcs = files([
	'cmath.h',
	'cmath1.c',
	'cmath1.h',
	'cmath2.c',
	'cmath2.h',
	'cmath3.c',
	'cmath3.h',
	'cmath4.c',
	'cmath4.h',
])

libcmaths = static_library(
	'cmaths',
	libcmaths_srcs,
	include_directories: [
		root_inc, poly_inc
	],
	install: false,
)
