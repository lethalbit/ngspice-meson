
subdir('include')

frontend_inc = include_directories('frontend')

subdir('spicelib')

if enable_xspice
	subdir('xspice')
endif

if enable_osdi
	subdir('osdi')
endif

if enable_cider
	subdir('ciderlib')
endif

subdir('frontend')
subdir('maths')
subdir('misc')

DYNAMIC_DEVICELIBS = [
	libasrc,
	libbjt,
	libbsim1,
	libbsim2,
	libbsim3,
	libbsim3v0,
	libbsim3v1,
	libbsim3v32,
	libbsim4,
	libbsim4v5,
	libbsim4v6,
	libbsim4v7,
	libcap,
	libbsim3soipd,
	libbsim3soifd,
	libbsim3soidd,
	libbsim4soi,
	libcccs,
	libccvs,
	libcpl,
	libcsw,
	libdio,
	libind,
	libisrc,
	libhfet,
	libhfet2,
	libhicum2,
	libhisim2,
	libhisimhv1,
	libhisimhv2,
	libjfet,
	libjfet2,
	libltra,
	libmes,
	libmesa,
	libmos1,
	libmos2,
	libmos3,
	libmos6,
	libmos9,
	libres,
	libsoi3,
	libsw,
	libtxl,
	libtra,
	liburc,
	libvbic,
	libvccs,
	libvcvs,
	libvdmos,
	libvsrc
]

if enable_ngshared
	libngspice_libs = [
		libfte,
		libplotting,
	]

	if enable_xspice
		libngspice_libs += [
			libcmxsp,
			libmifxsp,
		]
	endif

	libngspice_libs += [
		DYNAMIC_DEVICELIBS
	]

	if enable_ndev
		libngspice_libs += [
			libndev
		]
	endif

	if enable_numdev
		libngspice_libs += [
			libnbjt,
			libnbjt2,
			libnumd,
			libnumd2,
			libnumos,
		]
	endif

	libngspice_libs += [
		libckt,
		libdev,
	]

	if enable_xspice
		libngspice_libs += [
			libevtxsp,
			libenhxsp,
			libipcxsp,
			libidnxsp,
		]
	endif

	libngspice_libs += [
		libparser,
		libnumparam,
		libtrannoise,
		libinp,
	]

	if enable_cider
		libngspice_libs += [
			libcidertwod,
			libcideroned,
			libciderinput,
			libcidersuprt,
		]
	endif

	if enable_osdi
		libngspice_libs += [
			libosdi
		]
	endif

	libngspice_libs += [
		libderiv,
		libcmaths,
		libmathmisc,
		libmathfft,
		libpoly,
		libni,
		libsparse,
		libmisc,
	]

	if enable_sp
		libngspice_libs += [
			libdense
		]
	endif

	libngspice_srcs = files([
		'conf.c',
		'conf.h',
		'ngspice.c',
		'sharedspice.c',
	])

	libngspice = library(
		'ngspice',
		libngspice_srcs,
		link_with: [
			libngspice_libs,
		],
		cpp_args: [
			'-DSIMULATOR',
			'-DSHAREDSPICE_version='
		],
		c_args: [
			'-DSIMULATOR',
			'-DSHAREDSPICE_version=@0@'.format(meson.project_version())
		],
		dependencies: [
			threads, fftw3, dl_dep, omp
		],
		include_directories: [
			root_inc, frontend_inc, spicelib_devs_inc
		]
	)

	ngspice_dep = declare_dependency(
		dependencies: [
			threads, fftw3, dl_dep
		],
		link_with: libngspice,
		version: meson.project_version(),
		include_directories: [
			root_inc
		]
	)

else

	ngspice_srcs = files([
		'main.c',
		'conf.c',
		'conf.h',
		'ngspice.c',
	])

	ngspice_libs = [
		libfte,
		libplotting,

		DYNAMIC_DEVICELIBS,
	]

	if enable_ndev
		ngspice_libs += [
			libndev,
		]
	endif

	if enable_numdev
		ngspice_libs += [
			libnbjt,
			libnbjt2,
			libnumd,
			libnumd2,
			libnumos,
		]
	endif

	ngspice_libs += [
		libckt,
		libdev
	]

	if enable_xspice
		ngspice_libs += [
			libcmxsp,
			libmifxsp,
			libevtxsp,
			libenhxsp,
			libipcxsp,
			libidnxsp,
		]
	endif

	ngspice_libs += [
		libparser,
		libnumparam,
		libtrannoise,
		libinp,
	]

	if enable_cider
		ngspice_libs += [
			libcidertwod,
			libcideroned,
			libciderinput,
			libcidersuprt,
		]
	endif

	if enable_osdi
		ngspice_libs += [
			libosdi,
		]
	endif

	ngspice_libs += [
		libderiv,
		libcmaths,
		libmathmisc,
		libmathfft,
		libpoly,
		libni,
		libsparse,
		libmisc,
	]

	if enable_sp
		ngspice_libs += [
			libdense,
		]
	endif

	ngspice = executable(
		'ngspice',
		ngspice_srcs,
		link_with: [
			ngspice_libs
		],
		cpp_args: [
			'-DSIMULATOR'
		],
		c_args: [
			'-DSIMULATOR'
		],

		dependencies: [
			threads, fftw3, dl_dep, omp
		],
		include_directories: [
			root_inc, frontend_inc, spicelib_devs_inc
		]
	)

endif
