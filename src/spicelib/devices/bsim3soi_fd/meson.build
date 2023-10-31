
libbsim3soifd_srcs = files([
	'b3soifd.c',
	'b3soifdacld.c',
	'b3soifdask.c',
	'b3soifdcheck.c',
	'b3soifdcvtest.c',
	'b3soifdgetic.c',
	'b3soifdld.c',
	'b3soifdmask.c',
	'b3soifdmpar.c',
	'b3soifdnoi.c',
	'b3soifdpar.c',
	'b3soifdpzld.c',
	'b3soifdset.c',
	'b3soifdtemp.c',
	'b3soifdtrunc.c',
	'b3soifddef.h',
	'b3soifdext.h',
	'b3soifdinit.c',
	'b3soifdinit.h',
	'b3soifditf.h',
])

libbsim3soifd = static_library(
	'bsim3soifd',
	libbsim3soifd_srcs,
	include_directories: [ root_inc ],
	install: false,
)
