
libbsim3v0_srcs = files([
	'b3v0.c',
	'b3v0acld.c',
	'b3v0ask.c',
	'b3v0cvtest.c',
	'b3v0getic.c',
	'b3v0ld.c',
	'b3v0mask.c',
	'b3v0mpar.c',
	'b3v0noi.c',
	'b3v0par.c',
	'b3v0pzld.c',
	'b3v0set.c',
	'b3v0temp.c',
	'b3v0trunc.c',
	'bsim3v0def.h',
	'bsim3v0ext.h',
	'bsim3v0init.c',
	'bsim3v0init.h',
	'bsim3v0itf.h',
])

libbsim3v0 = static_library(
	'bsim3v0',
	libbsim3v0_srcs,
	include_directories: [ root_inc ],
	install: false,
)
