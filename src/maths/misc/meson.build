
libmathmisc_srcs = files([
	'accuracy.c',
	'accuracy.h',
	'bernoull.h',
	'bernoull.c',
	'equality.c',
	'isinf.c',
	'isnan.c',
	'logb.c',
	'scalb.c',
	'norm.h',
	'norm.c',
	'randnumb.c',
])

libmathmisc = static_library(
	'mathmisc',
	libmathmisc_srcs,
	include_directories: [ root_inc ],
	install: false,
)
