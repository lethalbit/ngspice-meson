
libnbjt_srcs = files([
	'nbjt.c',
	'nbjtacld.c',
	'nbjtask.c',
	'nbjtdefs.h',
	'nbjtdel.c',
	'nbjtdump.c',
	'nbjtext.h',
	'nbjtinit.c',
	'nbjtinit.h',
	'nbjtitf.h',
	'nbjtload.c',
	'nbjtmpar.c',
	'nbjtparm.c',
	'nbjtpzld.c',
	'nbjtset.c',
	'nbjttemp.c',
	'nbjttrun.c',
])

libnbjt = static_library(
	'nbjt',
	libnbjt_srcs,
	include_directories: [ root_inc ],
	install: false,
)
