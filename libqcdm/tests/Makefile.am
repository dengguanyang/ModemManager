if WITH_TESTS

INCLUDES = \
	-I$(top_srcdir)/libqcdm/src \
	-I$(top_srcdir)/src

noinst_PROGRAMS = test-qcdm

test_qcdm_SOURCES = \
	test-qcdm-crc.c \
	test-qcdm-crc.h \
	test-qcdm-escaping.c \
	test-qcdm-escaping.h \
	test-qcdm-utils.c \
	test-qcdm-utils.h \
	test-qcdm-com.c \
	test-qcdm-com.h \
	test-qcdm-result.c \
	test-qcdm-result.h \
	test-qcdm.c

test_qcdm_CPPFLAGS = $(MM_CFLAGS)

test_qcdm_LDADD = $(MM_LIBS)

if QCDM_STANDALONE
test_qcdm_LDADD += $(top_builddir)/src/libqcdm.la
else
test_qcdm_LDADD += $(top_builddir)/libqcdm/src/libqcdm.la
endif

check-local: test-qcdm
	$(abs_builddir)/test-qcdm

endif

