
libhfet_srcs = files([
	'hfet.c',
	'hfetacl.c',
	'hfetask.c',
	'hfetdefs.h',
	'hfetext.h',
	'hfetgetic.c',
	'hfetinit.c',
	'hfetinit.h',
	'hfetitf.h',
	'hfetload.c',
	'hfetmask.c',
	'hfetmpar.c',
	'hfetparam.c',
	'hfetpzl.c',
	'hfetsetup.c',
	'hfettemp.c',
	'hfettrunc.c',
])

libhfet = static_library(
	'hfet',
	libhfet_srcs,
	include_directories: [ root_inc ],
	install: false,
)
