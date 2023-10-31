
libmifxsp_srcs = files([
	'mif_inp2.c',
	'mifgetmod.c',
	'mifgetvalue.c',
	'mifload.c',
	'mifmpara.c',
	'mifsetup.c',
	'mifutil.c',
	'mifask.c',
	'mifmask.c',
	'miftrunc.c',
	'mifconvt.c',
	'mifdelete.c',
	'mifmdelete.c',
	'mifdestr.c',
	'mif.c',
])

libmifxsp = static_library(
	'mifxsp',
	libmifxsp_srcs,
	include_directories: [ root_inc ],
	install: false,
)
