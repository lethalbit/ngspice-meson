
# TODO: Bison parser

libinp_srcs = files([
	'ifeval.c',
	'ifnewuid.c',
	'inp2b.c',
	'inp2c.c',
	'inp2d.c',
	'inp2dot.c',
	'inp2e.c',
	'inp2f.c',
	'inp2g.c',
	'inp2h.c',
	'inp2i.c',
	'inp2j.c',
	'inp2k.c',
	'inp2l.c',
	'inp2m.c',
	'inp2o.c',
	'inp2p.c',
	'inp2q.c',
	'inp2r.c',
	'inp2s.c',
	'inp2t.c',
	'inp2u.c',
	'inp2v.c',
	'inp2w.c',
	'inp2y.c',
	'inp2z.c',
	'inpaname.c',
	'inpapnam.c',
	'inpcfix.c',
	'inpdomod.c',
	'inpdoopt.c',
	'inpdpar.c',
	'inperrc.c',
	'inperror.c',
	'inpeval.c',
	'inpfindl.c',
	'inpfindv.c',
	'inpgmod.c',
	'inpgstr.c',
	'inpgtitl.c',
	'inpgtok.c',
	'inpgval.c',
	'inpkmods.c',
	'inplist.c',
	'inplkmod.c',
	'inpmkmod.c',
	'inpmktmp.c',
	'inppas1.c',
	'inppas1.h',
	'inppas2.c',
	'inppas2.h',
	'inppas3.c',
	'inppas3.h',
	'inppas4.c',
	'inppas4.h',
	'inppname.c',
	'inpptree.c',
	'inpsymt.c',
	'inptyplk.c',
	'ptfuncs.c',
	'sperror.c',
	'inpxx.h',
])

libinp_srcs += bison_gen.process('inpptree-parser.y')

if enable_osdi
	libinp_srcs += files([
		'inp2n.c'
	])
endif

libinp = static_library(
	'inp',
	libinp_srcs,
	include_directories: [
		root_inc, frontend_inc, include_directories('.'),
	],
	install: false,
)
