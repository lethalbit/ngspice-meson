
libcidertwod_srcs = files([
	'twoadmit.c',
	'twoaval.c',
	'twocond.c',
	'twocont.c',
	'twocurr.c',
	'twoddefs.h',
	'twodest.c',
	'twodext.h',
	'twodopng.c',
	'twoelect.c',
	'twofield.c',
	'twomesh.c',
	'twomobdv.c',
	'twomobfn.c',
	'twomobil.c',
	'twoncont.c',
	'twopcont.c',
	'twopoiss.c',
	'twoprint.c',
	'twoproj.c',
	'tworead.c',
	'twosetbc.c',
	'twosetup.c',
	'twosolve.c',
])

libcidertwod = static_library(
	'cidertwod',
	libcidertwod_srcs,
	include_directories: [ root_inc ],
	install: false,
)
