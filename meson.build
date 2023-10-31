project(
	'ngspice',
	['c', 'cpp'],
	default_options: [
		'buildtype=release',
		'cpp_std=c++17',
		'c_std=c11',
		'warning_level=3',
		'b_ndebug=if-release',
	],
	version: '41',
	meson_version: '>=1',
)

cxx = meson.get_compiler('cpp')
cc  = meson.get_compiler('c')
os  = target_machine.system()

LIBNGSPICE_CURRENT     = 0
LIBNGSPICE_REVISION    = 8
LIBNGSPICE_AGE         = 1
LIBNGSPICE_SO_VERSION  = '@0@.@1@.@2@'.format(
	LIBNGSPICE_CURRENT, LIBNGSPICE_REVISION, LIBNGSPICE_AGE
)
LIBNGSPICE_API_VERSION = 0

enable_oldapps      = get_option('enable-oldapps')
enable_xspice       = get_option('enable-xspice')
enable_osdi         = get_option('enable-osdi')
enable_cider        = get_option('enable-cider')
enable_adms         = get_option('enable-adms')
enable_pss          = get_option('enable-pss')
enable_sp           = not get_option('disable-sp')
enable_relpath      = get_option('enable-relpath')
with_readline       = get_option('with-readline')
with_editline       = get_option('with-editline')
enable_ngshared     = get_option('enable-ngshared')
with_tcl            = get_option('with-tcl')
enable_utf8         = not get_option('disable-utf8')
enable_shortcheck   = get_option('enable-shortcheck')
enable_ansi         = get_option('enable-ansi')
enable_gprof        = get_option('enable-gprof')
enable_nobypass     = get_option('enable-nobypass')
enable_capbypass    = get_option('enable-capbypass')
enable_nodelimiting = get_option('enable-nodelimiting')
enable_predictor    = get_option('enable-predictor')
enable_newpred      = get_option('enable-newpred')
enable_newtruc      = get_option('enable-newtrunc')
enable_sense2       = get_option('enable-sense2')
enable_ftedebug     = get_option('enable-ftedebug')
enable_cpdebug      = get_option('enable-cpdebug')
enable_sensdebug    = get_option('enable-sensdebug')
enable_asdebug      = get_option('enable-asdebug')
enable_stepdebug    = get_option('enable-stepdebug')
enable_pzdebug      = get_option('enable-pzdebug')
enable_blktmsdebug  = get_option('enable-blktmsdebug')
enable_smltmsdebug  = get_option('enable-smltmsdebug')
enable_smoketest    = get_option('enable-smoketest')
enable_experimental = get_option('enable-experimental')
enable_expdevices   = get_option('enable-expdevices')
enable_ndev         = get_option('enable-ndev')
enable_cluster      = get_option('enable-cluster')
enable_help         = get_option('enable-help')
with_fftw3          = get_option('with-fftw3')
enable_openmp       = get_option('enable-openmp')
enable_numdev       = enable_cider


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

deps = [
	dependency('threads', required: true),
	cc.find_library('dl', required : true)
]

if with_fftw3
	deps += dependency('fftw3',   required: true)
endif

if enable_openmp
	deps += dependency('openmp',  required: true)
endif

if with_editline
	deps += dependency('editline',  required: true)
endif

if with_editline
	deps += dependency('readline',  required: true)
endif

if enable_smoketest
	extra_cflags += [
		'-pedantic',
		'-W',
		'-Wmissing-prototypes',
		'-Wstrict-prototypes',
		'-Wtraditional',
		'-Wconversion',
		'-Wshadow',
		'-Wpointer-arith',
		'-Wcast-qual',
		'-Wcast-align',
		'-Wwrite-strings',
		'-Waggregate-return',
		'-fshort-enums',
		'-fno-common',
		'-Wnested-externs',
		'-Dinline=',
	]
endif

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

if os == 'freebsd'
	conf.set('OS_COMPILED', 3)
elif os =='openbsd'
	conf.set('OS_COMPILED', 4)
elif os == 'sunos'
	conf.set('OS_COMPILED', 5)
elif os == 'linux'
	conf.set('OS_COMPILED', 6)
elif os == 'darwin'
	conf.set('OS_COMPILED', 7)
else
	conf.set('OS_COMPILED', 0)
endif

conf.set('SHARED_MODULE', enable_ngshared)
conf.set('X_DISPLAY_MISSING', 1)

if enable_relpath
	conf.set_quoted('NGSPICEBINDIR', '../bin')
	conf.set_quoted('NGSPICEDATADIR', '../share/ngspice')
else
	conf.set_quoted('NGSPICEBINDIR', get_option('prefix') / get_option('bindir'))
	conf.set_quoted('NGSPICEDATADIR', get_option('prefix') / get_option('datadir') / 'ngspice')
endif

date = find_program('date', required: false, native: true)
if date.found()
	datetime = run_command(date, '--utc', check: false).stdout().strip()
	conf.set_quoted('NGSPICEBUILDDATE', datetime)
else
	conf.set_quoted('NGSPICEBUILDDATE', '')
endif


conf.set('ADMS',   enable_adms)
conf.set('CIDER',  enable_cider)
conf.set('XSPICE', enable_xspice)
conf.set('OSDI',   enable_osdi)
conf.set('ASDEBUG', enable_asdebug)
conf.set('CAPBYPASS', enable_capbypass)
conf.set('CLUSTER', enable_cluster)
conf.set('CPDEBUG', enable_cpdebug)
conf.set('D_DBG_BLOCKTIMES', enable_blktmsdebug)
conf.set('D_DBG_SMALLTIMES', enable_smltmsdebug)
conf.set('EXPERIMENTAL_CODE', enable_experimental)
conf.set('EXP_DEV', enable_expdevices)
conf.set('EXT_ASC', enable_utf8)
conf.set('FTEDEBUG', enable_ftedebug)
conf.set('HAS_RELPATH', enable_relpath)
conf.set('NDEV', enable_ndev)
conf.set('NEWPRED', enable_newpred)
conf.set('NEWTRUNC', enable_newtruc)
conf.set('NGDEBUG', get_option('buildtype') == 'debug')
conf.set('NOBYPASS', enable_nobypass)
conf.set('NODELIMITING', enable_nodelimiting)
conf.set('PREDICTOR', enable_predictor)
conf.set('SENSDEBUG', enable_sensdebug)
conf.set('STEPDEBUG', enable_stepdebug)
conf.set('USE_OMP', enable_openmp)
conf.set('YYTEXT_POINTER', 1)
conf.set('RFSPICE', enable_sp)
conf.set('IPC_UNIX_SOCKETS', 1)
conf.set('NOINTHELP', 1)
conf.set('HAVE_LIBFFTW3', with_fftw3)
conf.set('STDC_HEADERS', 1)
conf.set_quoted('PACKAGE', meson.project_name())
conf.set_quoted('PACKAGE_BUGREPORT', 'https://github.com/lethalbit/ngspice-meson')
conf.set_quoted('PACKAGE_NAME', meson.project_name())
conf.set_quoted('PACKAGE_STRING', '@0@ @1@'.format(meson.project_name(), meson.project_version()))
conf.set_quoted('PACKAGE_TARNAME', meson.project_name())
conf.set_quoted('PACKAGE_URL', 'https://github.com/lethalbit/ngspice-meson')
conf.set_quoted('PACKAGE_VERSION', meson.project_version())
conf.set_quoted('VERSION', meson.project_version())


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
	'signal.h': [
		'sig_t', '__sighandler_t', 'sighandler_t'
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
	'termcap.h': [],
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

has_termios = cc.check_header('termios.h')
if not has_termios
	has_termio  = cc.check_header('termio.h')
	conf.set('HAVE_TERMIO_H', 1)
else
	conf.set('HAVE_TERMIOS_H', 1)
	foreach fnc : [ 'tcgetattr', 'tcsetattr', 'tdestroy' ]
		if cc.has_function(fnc)
			conf.set('HAVE_@0@'.format(
				fnc.to_upper()
			), 1)
		endif
	endforeach
endif

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
