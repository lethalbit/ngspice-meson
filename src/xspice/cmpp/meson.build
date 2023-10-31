
cmpp_srcs = files([
	'main.c',
	'cmpp.h',
	'file_buffer.c',
	'file_buffer.h',
	'pp_ifs.c',
	'pp_lst.c',
	'pp_mod.c',
	'read_ifs.c',
	'writ_ifs.c',
	'util.c',
	'ifs_yacc_y.h',
	'mod_yacc_y.h',
])

cmpp_srcs += [
	flex_gen.process('ifs_lex.l'),
	bison_gen.process('ifs_yacc.y'),
	flex_gen.process('mod_lex.l'),
	bison_gen.process('mod_yacc.y')
]


cmpp_exe = executable(
	'cmpp',
	cmpp_srcs,
	include_directories: [ root_inc ],
	install: false,
)

cmpp_ifs = generator(
	cmpp_exe,
	output: '@PLAINNAME@',
	arguments: [
		'-ifs'
	]
)

cmpp_lst = generator(
	cmpp_exe,
	output: '@PLAINNAME@',
	arguments: [
		'-lst'
	]
)

cmpp_mod = generator(
	cmpp_exe,
	output: '@PLAINNAME@',
	arguments: [
		'-mod', '@INPUT@'
	]
)
