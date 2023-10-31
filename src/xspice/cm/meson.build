
libcmxsp_srcs = files([
	'cm.c',
	'cmevt.c',
	'cmmeters.c',
	'cmutil.c',
	'cmexport.c',
])

libcmxsp = static_library(
	'cmxsp',
	libcmxsp_srcs,
	include_directories: [
		root_inc, spicelib_devs_inc
	],
	install: false,
)
