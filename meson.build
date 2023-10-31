project(
	'ngspice',
	['c', 'cpp'],
	default_options: [
		'buildtype=release',
		'cpp_std=c++17',
		'c_std=c17',
		'warning_level=3',
		'b_ndebug=if-release',
	],
	version: '41',
	meson_version: '>=1',
)

cxx = meson.get_compiler('cpp')
cc  = meson.get_compiler('c')

enable_oldapps    = get_option('enable-oldapps')
enable_xspice     = get_option('enable-xspice')
enable_osdi       = get_option('enable-osdi')
enable_cider      = get_option('enable-cider')
enable_adms       = get_option('enable-adms')
enable_pss        = get_option('enable-pss')
enable_sp         = not get_option('disable-sp')
enable_relpath    = get_option('enable-relpath')
with_readline     = get_option('with-readline')
with_editline     = get_option('with-editline')
enable_ngshared   = get_option('enable-ngshared')
with_tcl          = get_option('with-tcl')
enable_utf8       = not get_option('disable-utf8')
enable_shortcheck = get_option('enable-shortcheck')
enable_ndev       = get_option('enable-ndev')
enable_cluster    = get_option('enable-cluster')
enable_numdev     = enable_cider


if with_editline and with_editline
	error('Readline and editline can not be both enabled')
endif

extra_cflags = [
	'-Wmissing-prototypes',
	'-Wstrict-prototypes',
	'-Wnested-externs',
	'-Wold-style-definition',
	'-Wredundant-decls',
	'-Wconversion',
	'-Wno-unused-but-set-variable',
]

flex  = find_program('flex', required: true)
bison = find_program('bison', required: true)

threads = dependency('threads', required: true)
fftw3   = dependency('fftw3',   required: true)
omp     = dependency('openmp',  required: true)
dl_dep  = cc.find_library('dl', required : true)


add_project_arguments(
	cc.get_supported_arguments(extra_cflags),
	language: 'c'
)

flex_gen = generator(
	flex,
	output: '@PLAINNAME@.yy.c',
	arguments: [
		'-o', '@OUTPUT@', '@INPUT@'
	]
)

bison_gen = generator(
	bison,
	output : [
		'@BASENAME@.tab.c',
		'@BASENAME@.h'
	],
	arguments : [
		'@INPUT@',
		'--defines=@OUTPUT1@',
		'--output=@OUTPUT0@'
	]
)


conf = configuration_data()

conf.set('ADMS',   enable_adms)
conf.set('CIDER',  enable_cider)
conf.set('XSPICE', enable_xspice)
conf.set('OSDI',   enable_osdi)



conf.set('STDC_HEADERS', 1)

conf.set_quoted('NGSPICEBINDIR', get_option('prefix') / get_option('bindir'))
conf.set_quoted('NGSPICEBUILDDATE' ,'')
conf.set_quoted('NGSPICEDATADIR', get_option('prefix') / get_option('datadir'))
conf.set_quoted('PACKAGE', meson.project_name())
conf.set_quoted('PACKAGE_BUGREPORT', 'https://github.com/lethalbit/ngspice-meson')
conf.set_quoted('PACKAGE_NAME', meson.project_name())
conf.set_quoted('PACKAGE_STRING', '@0@ @1@'.format(meson.project_name(), meson.project_version()))
conf.set_quoted('PACKAGE_TARNAME', meson.project_name())
conf.set_quoted('PACKAGE_URL', 'https://github.com/lethalbit/ngspice-meson')
conf.set_quoted('PACKAGE_VERSION', meson.project_version())
conf.set_quoted('VERSION', meson.project_version())
conf.set('RFSPICE', 1)
conf.set('SHARED_MODULE', enable_ngshared)
conf.set('X_DISPLAY_MISSING', 1)
conf.set('IPC_UNIX_SOCKETS', 1)
conf.set('NOINTHELP', 1)
conf.set('HAVE_LIBFFTW3', 1)
conf.set('OS_COMPILED', 6)
conf.set('USE_OMP', 1)
conf.set('YYTEXT_POINTER', 1)


needed_headers = {
	'unistd.h': [
		'access', 'dup2', 'fork', 'getcwd', 'getwd',
		'isatty', 'vfork'
	],
	'math.h': [
		'acosh', 'asinh', 'atanh', 'isinf', 'isnan',
		'erfc', 'finite', 'logb', 'modf', 'scalb',
		'scalbn'
	],
	'arpa/inet.h': [],
	'ctype.h': [],
	'dirent.h': [],
	'libgen.h': [
		'dirname',
	],
	'netdb.h': [
		'gethostbyname'
	],
	'dlfcn.h': [],
	'pwd.h': [
		'endpwend',
	],
	'sys/timeb.h': [
		'ftime'
	],
	'time.h': [
		'localtime'
	],
	'sys/time.h': [
		'gettimeofday', 'utimes'
	],
	'fcntl.h': [],
	'fftw3.h': [],
	'float.h': [],
	'getopt.h': [
		'getopt_long'
	],
	'sys/resource.h': [
		'getrlimit',
	],
	'ieeefp.h': [],
	'inttypes.h': [],
	'libintl.h': [],
	'limits.h': [],
	'malloc.h': [],
	'string.h': [
		'memset', 'strchr', 'strdup',
		'strerror', 'strrchr', 'strstr', 'strtol'
	],
	'netinet/in.h': [],
	'stdio.h': [
		'popen', 'snprintf', 'vprintf',
	],
	'stdlib.h': [
		'qsort',
	],
	'sys/select.h': [
		'select'
	],
	'setjmp.h': [
		'sigsetjmp'
	],
	'stdbool.h': [],
	'stdint.h': [],
	'sys/socket.h': [
		'socket'
	],
	'strings.h': [
		'strncasecmp',
	],
	'stropts.h': [],
	'sys/dir.h': [],
	'sys/file.h': [],
	'sys/ioctl.h': [],
	'sys/io.h': [],
	'sys/ndir.h': [],
	'sys/param.h': [],
	'sys/stat.h': [],
	'sys/sysctl.h': [],
	'sys/types.h': [],
	'sys/wait.h': [],
	'termios.h': [
		'tcgetattr', 'tcsetattr', 'tdestroy'
	],
	'termcap.h': [],
	'termio.h': [],
	'search.h': [
		'tsearch'
	],
	'values.h': [],
	'vfork.h': []
}

foreach hdr, fncs : needed_headers
	if cc.check_header(hdr)
		conf.set('HAVE_@0@'.format(
			hdr.replace('.','_').replace('/', '_').to_upper()
		), 1)
		foreach fnc : fncs
			if cc.has_function(fnc)
				conf.set('HAVE_@0@'.format(
					fnc.to_upper()
				), 1)
			endif
		endforeach
	endif
endforeach

needed_libs = [
	'libm',
	'libpthread',
]

foreach lib : needed_libs
	if cc.find_library(lib).found()
		conf.set('HAVE_@0@'.format(
			lib.to_upper()
		), 1)
	endif
endforeach


subdir('src')
