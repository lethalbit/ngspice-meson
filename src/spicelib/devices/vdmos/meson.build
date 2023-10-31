
libvdmos_srcs = files([
	'vdmos.c',
	'vdmosacld.c',
	'vdmosask.c',
	'vdmosconv.c',
	'vdmosdefs.h',
	'vdmosdist.c',
	'vdmosdset.c',
	'vdmosext.h',
	'vdmosic.c',
	'vdmosinit.c',
	'vdmosinit.h',
	'vdmositf.h',
	'vdmosload.c',
	'vdmosmask.c',
	'vdmosmpar.c',
	'vdmosnoi.c',
	'vdmospar.c',
	'vdmospzld.c',
	'vdmosset.c',
	'vdmossoachk.c',
	'vdmostemp.c',
	'vdmostrun.c',
])

libvdmos = static_library(
	'vdmos',
	libvdmos_srcs,
	include_directories: [ root_inc ],
	install: false,
)
