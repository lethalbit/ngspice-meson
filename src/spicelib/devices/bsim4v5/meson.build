
libbsim4v5_srcs = files([
	'b4v5.c',
	'b4v5acld.c',
	'b4v5ask.c',
	'b4v5check.c',
	'b4v5cvtest.c',
	'b4v5geo.c',
	'b4v5getic.c',
	'b4v5ld.c',
	'b4v5mask.c',
	'b4v5mdel.c',
	'b4v5mpar.c',
	'b4v5noi.c',
	'b4v5par.c',
	'b4v5pzld.c',
	'b4v5set.c',
	'b4v5soachk.c',
	'b4v5temp.c',
	'b4v5trunc.c',
	'bsim4v5def.h',
	'bsim4v5ext.h',
	'bsim4v5init.c',
	'bsim4v5init.h',
	'bsim4v5itf.h',
])

libbsim4v5 = static_library(
	'bsim4v5',
	libbsim4v5_srcs,
	include_directories: [ root_inc ],
	install: false,
)
