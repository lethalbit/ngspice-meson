
libhisim2_srcs = files([
	'hsm2.c',
	'hsm2acld.c',
	'hsm2ask.c',
	'hsm2cvtest.c',
	'hsm2def.h',
	'hsm2eval.c',
	'hsm2evalenv.h',
	'hsm2eval_dep.h',
	'hsm2ext.h',
	'hsm2getic.c',
	'hsm2init.c',
	'hsm2init.h',
	'hsm2itf.h',
	'hsm2ld.c',
	'hsm2mask.c',
	'hsm2mdel.c',
	'hsm2mpar.c',
	'hsm2noi.c',
	'hsm2par.c',
	'hsm2pzld.c',
	'hsm2set.c',
	'hsm2soachk.c',
	'hsm2temp.c',
	'hsm2trunc.c',
])

libhisim2 = static_library(
	'hisim2',
	libhisim2_srcs,
	include_directories: [ root_inc ],
	install: false,
)
