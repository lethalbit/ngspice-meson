
# subdir('adms')
subdir('asrc')
subdir('bjt')
subdir('bsim1')
subdir('bsim2')
subdir('bsim3')
subdir('bsim3soi_dd')
subdir('bsim3soi_fd')
subdir('bsim3soi_pd')
subdir('bsim3v0')
subdir('bsim3v1')
subdir('bsim3v32')
subdir('bsim4')
subdir('bsim4v5')
subdir('bsim4v6')
subdir('bsim4v7')
subdir('bsimsoi')
subdir('cap')
subdir('cccs')
subdir('ccvs')
subdir('cpl')
subdir('csw')
subdir('dio')
subdir('hfet1')
subdir('hfet2')
subdir('hicum2')
subdir('hisim2')
subdir('hisimhv1')
subdir('hisimhv2')
subdir('ind')
subdir('isrc')
subdir('jfet')
subdir('jfet2')
subdir('ltra')
subdir('mes')
subdir('mesa')
subdir('mos1')
subdir('mos2')
subdir('mos3')
subdir('mos6')
subdir('mos9')

subdir('res')
subdir('soi3')
subdir('sw')
subdir('tra')
subdir('txl')
subdir('urc')
subdir('vbic')
subdir('vccs')
subdir('vcvs')
subdir('vdmos')
subdir('vsrc')

if enable_ndev
	subdir('ndev')
endif

if enable_numdev
	subdir('nbjt')
	subdir('nbjt2')
	subdir('numd')
	subdir('numd2')
	subdir('numos')
endif

libdev_srcs = files([
	'dev.c',
	'dev.h',
	'devsup.c',
	'cktaccept.c',
	'cktaccept.h',
	'cktask.c',
	'cktbindnode.c',
	'cktcrte.c',
	'cktfinddev.c',
	'cktinit.c',
	'cktsoachk.c',
	'limit.c',
])

libdev = static_library(
	'dev',
	libdev_srcs,
	include_directories: [
		root_inc, spicelib_devs_inc
	],
	install: false,
)
