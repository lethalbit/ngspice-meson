
libnumd_srcs = files([
	'numd.c',
	'numdacld.c',
	'numdask.c',
	'numddefs.h',
	'numddel.c',
	'numddump.c',
	'numdext.h',
	'numdinit.c',
	'numdinit.h',
	'numditf.h',
	'numdload.c',
	'numdmpar.c',
	'numdparm.c',
	'numdpzld.c',
	'numdset.c',
	'numdtemp.c',
	'numdtrun.c',
])

libnumd = static_library(
	'numd',
	libnumd_srcs,
	include_directories: [ root_inc ],
	install: false,
)
