AC_INIT(perror, 1.0.0, james@stev.org)
AC_CONFIG_AUX_DIR(config)
AC_CONFIG_SRCDIR([src/perror.c])
AC_CONFIG_MACRO_DIR([m4])

LT_INIT
AM_INIT_AUTOMAKE([foreign])
AM_SILENT_RULES([yes])

AC_PROG_CC
AC_PROG_LIBTOOL


m4_ifdef([AX_COMPILER_FLAGS],
        [
                AX_COMPILER_FLAGS([WARN_CFLAGS],[WARN_LDFLAGS])
                AC_SUBST([AM_CXXFLAGS], $WARN_CXXFLAGS)
        ]
,
        [
                AC_SUBST([AM_CXXFLAGS], ['-Wall -Werror'])
        ]
)

AC_OUTPUT(Makefile
	doc/Makefile
	src/Makefile

)


