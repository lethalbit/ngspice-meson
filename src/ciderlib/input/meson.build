
libciderinput_srcs = files([
	'bdryset.c',
	'boundary.c',
	'cards.c',
	'contact.c',
	'contset.c',
	'domain.c',
	'domnset.c',
	'doping.c',
	'dopset.c',
	'elctset.c',
	'electrod.c',
	'material.c',
	'matlset.c',
	'mesh.c',
	'meshset.c',
	'method.c',
	'mobility.c',
	'mobset.c',
	'models.c',
	'modlset.c',
	'optionsc.c',
	'outpset.c',
	'output.c'
])

libciderinput = static_library(
	'ciderinput',
	libciderinput_srcs,
	include_directories: [ root_inc ],
	install: false,
)
