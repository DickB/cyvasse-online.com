AC_INIT([cyvasse-online],[0.1],[mail@jonasplatte.de])
AC_CONFIG_AUX_DIR([.])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([1.11 foreign])
AM_SILENT_RULES([yes])
AC_PROG_CXX
AC_LANG(C++)

AC_CHECK_PROGS(ECPPC, [ecppc])
AC_CHECK_HEADER([tnt/tntnet.h], [], AC_MSG_ERROR([tntnet headers not found]))
AC_CHECK_HEADER([tntdb/connection.h], [], AC_MSG_ERROR([tntdb headers not found]))
AC_PROG_SED


PKG_CHECK_MODULES([CPPUNIT], [cppunit], [have_cppunit=yes], [have_cppunit=no])
AM_CONDITIONAL([HAVE_CPPUNIT], [test "$have_cppunit" = "yes"])

AC_CONFIG_SUBDIRS([game])

AC_CONFIG_FILES([
	Makefile
	webapp-conf.json
	webapp/Makefile
	unit-tests/Makefile
])
AC_OUTPUT
