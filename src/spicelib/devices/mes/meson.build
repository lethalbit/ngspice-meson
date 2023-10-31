
libmes_srcs = files([
	'mes.c',
	'mesacl.c',
	'mesask.c',
	'mesdefs.h',
	'mesdisto.c',
	'mesdset.c',
	'mesext.h',
	'mesgetic.c',
	'mesinit.c',
	'mesinit.h',
	'mesitf.h',
	'mesload.c',
	'mesmask.c',
	'mesmpar.c',
	'mesnoise.c',
	'mesparam.c',
	'mespzld.c',
	'messetup.c',
	'mestemp.c',
	'mestrunc.c',
])

libmes = static_library(
	'mes',
	libmes_srcs,
	include_directories: [ root_inc ],
	install: false,
)
