# Process this file with automake

EXTRA_DIST = README examples icm xspice.c .gitignore \
             verilog/vlnggen \
             verilog/verilator_shim.cpp verilog/verilator_main.cpp

## This is removed because icm relies upon the existance of all other
## libs.  It is currently compiled manually, last.
##SUBDIRS = mif cm enh evt ipc idn icm

SUBDIRS = mif cm enh evt ipc idn cmpp icm

initdatadir = $(pkgdatadir)/scripts
initdata_DATA = verilog/vlnggen

initdata1dir = $(pkgdatadir)/scripts/src
initdata1_DATA = verilog/verilator_shim.cpp verilog/verilator_main.cpp

initdata2dir = $(pkgdatadir)/scripts/src/ngspice
initdata2_DATA = ../include/ngspice/cosim.h ../include/ngspice/miftypes.h \
                 ../include/ngspice/cmtypes.h
dist-hook:
	rm -f "$(distdir)/icm/makedefs"
	rm -f "$(distdir)/icm/GNUmakefile"
	rm -rf `find $(distdir)/icm -name .deps`
	rm -rf `find $(distdir)/icm -name *.o`
	rm -rf `find $(distdir)/icm -name *.cm`
	for sub in analog digital spice2poly xtradev xtraevt table ; do \
	    rm -rf `find $(distdir)/icm/$$sub -name cmextrn.h`; \
	    rm -rf `find $(distdir)/icm/$$sub -name cminfo.h`; \
	    rm -rf `find $(distdir)/icm/$$sub -name udnextrn.h`; \
	    rm -rf `find $(distdir)/icm/$$sub -name udninfo.h`; \
	    rm -rf `find $(distdir)/icm/$$sub -name ifspec.c`; \
	    rm -rf `find $(distdir)/icm/$$sub -name cfunc.c`; \
	    rm -rf `find $(distdir)/icm/$$sub -name dlmain.c`; \
	    rm -rf `find $(distdir)/icm/$$sub -name objects.inc`; \
	done

MAINTAINERCLEANFILES = Makefile.in
