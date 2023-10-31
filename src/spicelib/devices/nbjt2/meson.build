
libnbjt2_srcs = files([
	'nbt2.c',
	'nbt2acld.c',
	'nbt2ask.c',
	'nbjt2def.h',
	'nbt2del.c',
	'nbt2dump.c',
	'nbjt2ext.h',
	'nbt2init.c',
	'nbt2init.h',
	'nbjt2itf.h',
	'nbt2load.c',
	'nbt2mpar.c',
	'nbt2parm.c',
	'nbt2pzld.c',
	'nbt2set.c',
	'nbt2temp.c',
	'nbt2trun.c'
])

libnbjt2 = static_library(
	'nbjt2',
	libnbjt2_srcs,
	include_directories: [ root_inc ],
	install: false,
)
