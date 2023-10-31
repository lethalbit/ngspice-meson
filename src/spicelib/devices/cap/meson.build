
libcap_srcs = files([
	'cap.c',
	'capacld.c',
	'capask.c',
	'capdefs.h',
	'capext.h',
	'capgetic.c',
	'capinit.c',
	'capinit.h',
	'capitf.h',
	'capload.c',
	'capmask.c',
	'capmpar.c',
	'capparam.c',
	'cappzld.c',
	'capsacl.c',
	'capsetup.c',
	'capsload.c',
	'capsoachk.c',
	'capsprt.c',
	'capsset.c',
	'capsupd.c',
	'captemp.c',
	'captrunc.c',
])

libcap = static_library(
	'cap',
	libcap_srcs,
	include_directories: [ root_inc ],
	install: false,
)
