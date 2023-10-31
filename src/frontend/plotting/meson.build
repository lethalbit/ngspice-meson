
libplotting_srcs = files([
	'plotting.c',
	'plotting.h',
	'agraf.c',
	'agraf.h',
	'clip.c',
	'clip.h',
	'gnuplot.c',
	'gnuplot.h',
	'graf.c',
	'graf.h',
	'graphdb.c',
	'graphdb.h',
	'grid.c',
	'pvec.c',
	'pvec.h',
	'plot5.c',
	'plot5.h',
	'plotcurv.c',
	'plotcurv.h',
	'plotit.c',
	'plotit.h',
])

libplotting = static_library(
	'plotting',
	libplotting_srcs,
	include_directories: [
		root_inc, frontend_inc
	],
	install: false,
)
