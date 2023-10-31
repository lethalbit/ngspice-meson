
libderiv_srcs = files([
	'atander.c',
	'cosderiv.c',
	'cubeder.c',
	'divderiv.c',
	'equalder.c',
	'expderiv.c',
	'invderiv.c',
	'multder.c',
	'plusder.c',
	'powderiv.c',
	'sqrtder.c',
	'tanderiv.c',
	'timesder.c',
])

libderiv = static_library(
	'deriv',
	libderiv_srcs,
	include_directories: [ root_inc ],
	install: false,
)
