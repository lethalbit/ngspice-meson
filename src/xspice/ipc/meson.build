
libipcxsp_srcs = files([
	'ipcaegis.c',
	'ipc.c',
	'ipcsockets.c',
	'ipcstdio.c',
	'ipctiein.c',
])

libipcxsp = static_library(
	'ipcxsp',
	libipcxsp_srcs,
	include_directories: [
		root_inc, spicelib_devs_inc
	],
	install: false,
)
