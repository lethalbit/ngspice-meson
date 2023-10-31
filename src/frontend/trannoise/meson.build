

libtrannoise_srcs = files([
	'FastNorm3.c',
	'1-f-code.c',
	'wallace.c',
])

libtrannoise = static_library(
	'trannoise',
	libtrannoise_srcs,
	include_directories: [
		root_inc, frontend_inc
	],
	install: false,
)
