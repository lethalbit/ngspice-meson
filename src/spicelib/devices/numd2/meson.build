
libnumd2_srcs = files([
	'nud2.c',
	'nud2acld.c',
	'nud2ask.c',
	'numd2def.h',
	'nud2del.c',
	'nud2dump.c',
	'numd2ext.h',
	'numd2init.c',
	'numd2init.h',
	'numd2itf.h',
	'nud2load.c',
	'nud2mpar.c',
	'nud2parm.c',
	'nud2pzld.c',
	'nud2set.c',
	'nud2temp.c',
	'nud2trun.c',
])

libnumd2 = static_library(
	'numd2',
	libnumd2_srcs,
	include_directories: [ root_inc ],
	install: false,
)
