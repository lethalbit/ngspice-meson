
libndev_srcs = files([
	'ndev.c',
	'ndevacld.c',
	'ndevaccept.c',
	'ndevask.c',
	'ndevdefs.h',
	'ndevdump.c',
	'ndevext.h',
	'ndevexch.h',
	'ndevinit.c',
	'ndevinit.h',
	'ndevitf.h',
	'ndevload.c',
	'ndevmdel.c',
	'ndevmpar.c',
	'ndevparm.c',
	'ndevpzld.c',
	'ndevset.c',
	'ndevtemp.c',
	'ndevtrun.c',
])

libndev = static_library(
	'ndev',
	libndev_srcs,
	include_directories: [ root_inc ],
	install: false,
)
