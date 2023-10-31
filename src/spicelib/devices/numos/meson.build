
libnumos_srcs = files([
	'numm.c',
	'nummacld.c',
	'nummask.c',
	'numosdef.h',
	'nummdel.c',
	'nummdump.c',
	'numosext.h',
	'numosinit.c',
	'numosinit.h',
	'numositf.h',
	'nummload.c',
	'nummmpar.c',
	'nummparm.c',
	'nummpzld.c',
	'nummset.c',
	'nummtemp.c',
	'nummtrun.c',
])

libnumos = static_library(
	'numos',
	libnumos_srcs,
	include_directories: [ root_inc ],
	install: false,
)
