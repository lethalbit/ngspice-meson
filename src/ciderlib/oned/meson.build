
libcideroned_srcs = files([
	'oneadmit.c',
	'oneaval.c',
	'onecond.c',
	'onecont.c',
	'oneddefs.h',
	'onedest.c',
	'onedext.h',
	'onedopng.c',
	'onefreez.c',
	'onemesh.c',
	'onepoiss.c',
	'oneprint.c',
	'oneproj.c',
	'oneread.c',
	'onesetup.c',
	'onesolve.c',
])

libcideroned = static_library(
	'cideroned',
	libcideroned_srcs,
	include_directories: [ root_inc ],
	install: false,
)
