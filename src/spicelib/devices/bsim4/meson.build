
libbsim4_srcs = files([
	'b4.c',
	'b4acld.c',
	'b4ask.c',
	'b4check.c',
	'b4cvtest.c',
	'b4geo.c',
	'b4getic.c',
	'b4ld.c',
	'b4mask.c',
	'b4mdel.c',
	'b4mpar.c',
	'b4noi.c',
	'b4par.c',
	'b4pzld.c',
	'b4set.c',
	'b4soachk.c',
	'b4temp.c',
	'b4trunc.c',
	'bsim4def.h',
	'bsim4ext.h',
	'bsim4init.c',
	'bsim4init.h',
	'bsim4itf.h',
])

libbsim4 = static_library(
	'bsim4',
	libbsim4_srcs,
	include_directories: [ root_inc ],
	install: false,
)
