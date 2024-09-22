## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = project9

project9_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	Don.c Don.h \
	source.c source.h \
	source_ets.c source_ets.h \
	donneur.c donneur.h \
	rdv.c rdv.h

project9_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

