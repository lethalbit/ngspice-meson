
libbsim4soi_srcs = files([
    'b4soi.c',
    'b4soiacld.c',
    'b4soiask.c',
    'b4soicheck.c',
    'b4soicvtest.c',
    'b4soigetic.c',
    'b4soild.c',
    'b4soimask.c',
    'b4soimdel.c',
    'b4soimpar.c',
    'b4soinoi.c',
    'b4soipar.c',
    'b4soipzld.c',
    'b4soiset.c',
    'b4soisoachk.c',
    'b4soitemp.c',
    'b4soitrunc.c',
    'b4soidef.h',
    'b4soiext.h',
    'b4soiinit.c',
    'b4soiinit.h',
    'b4soiitf.h',
])

libbsim4soi = static_library(
	'bsim4soi',
	libbsim4soi_srcs,
	include_directories: [ root_inc ],
	install: false,
)
