
libmathfft_srcs = files([
	'fftext.c',
	'fftlib.c',
	'fftlib.h',
	'matlib.c',
	'matlib.h',
])

libmathfft = static_library(
	'mathfft',
	libmathfft_srcs,
	include_directories: [ root_inc ],
	install: false,
)
