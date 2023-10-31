
libvbic_srcs = files([
	'vbic.c',
	'vbicacld.c',
	'vbicask.c',
	'vbicconv.c',
	'vbicdefs.h',
	'vbicext.h',
	'vbicgetic.c',
	'vbicinit.c',
	'vbicinit.h',
	'vbicitf.h',
	'vbicload.c',
	'vbicmask.c',
	'vbicmpar.c',
	'vbicnoise.c',
	'vbicparam.c',
	'vbicpzld.c',
	'vbicsetup.c',
	'vbicsoachk.c',
	'vbictemp.c',
	'vbictrunc.c',
])

libvbic = static_library(
	'vbic',
	libvbic_srcs,
	include_directories: [ root_inc ],
	install: false,
)
