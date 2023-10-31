
libbsim4v7_srcs = files([
	'b4v7.c',
	'b4v7acld.c',
	'b4v7ask.c',
	'b4v7check.c',
	'b4v7cvtest.c',
	'b4v7geo.c',
	'b4v7getic.c',
	'b4v7ld.c',
	'b4v7mask.c',
	'b4v7mdel.c',
	'b4v7mpar.c',
	'b4v7noi.c',
	'b4v7par.c',
	'b4v7pzld.c',
	'b4v7set.c',
	'b4v7soachk.c',
	'b4v7temp.c',
	'b4v7trunc.c',
	'bsim4v7def.h',
	'bsim4v7ext.h',
	'bsim4v7init.c',
	'bsim4v7init.h',
	'bsim4v7itf.h',
])

libbsim4v7 = static_library(
	'bsim4v7',
	libbsim4v7_srcs,
	include_directories: [ root_inc ],
	install: false,
)
