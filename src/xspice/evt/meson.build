
libevtxsp_srcs = files([
	'evtaccept.c',
	'evtcall_hybrids.c',
	'evtdump.c',
	'evtiter.c',
	'evtnext_time.c',
	'evtop.c',
	'evtprint.c',
	'evtsetup.c',
	'evtdest.c',
	'evtbackup.c',
	'evtdeque.c',
	'evtinit.c',
	'evtload.c',
	'evtnode_copy.c',
	'evtplot.c',
	'evtqueue.c',
	'evttermi.c',
	'evtshared.c',
	'evtcheck_nodes.c',
])

libevtxsp = static_library(
	'evtxsp',
	libevtxsp_srcs,
	include_directories: [ root_inc ],
	install: false,
)
