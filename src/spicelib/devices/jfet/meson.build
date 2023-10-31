
libjfet_srcs = files([
	'jfet.c',
	'jfetacld.c',
	'jfetask.c',
	'jfetdefs.h',
	'jfetdist.c',
	'jfetdset.c',
	'jfetext.h',
	'jfetic.c',
	'jfetinit.c',
	'jfetinit.h',
	'jfetitf.h',
	'jfetload.c',
	'jfetmask.c',
	'jfetmpar.c',
	'jfetnoi.c',
	'jfetpar.c',
	'jfetpzld.c',
	'jfetset.c',
	'jfettemp.c',
	'jfettrun.c',
])

libjfet = static_library(
	'jfet',
	libjfet_srcs,
	include_directories: [ root_inc ],
	install: false,
)
