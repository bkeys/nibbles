#AUTOCONF REQUIREMENTS
AC_INIT([snake], [1], [bkeys@bkeys.org], [snake], [http://www.bkeys.org])

#AUTOCONF MINIMUM VERSION NUMBER
AC_PREREQ(2.68)

#Require this file to exist
AC_CONFIG_SRCDIR([src/main.cpp])

#PUT CONFIGURATION HERE IN A HEADER FILE THAT WILL BE #INCLUDED
AC_CONFIG_HEADERS([src/config.h])

#using an m4 directory
AC_CONFIG_MACRO_DIR([m4])

#checking for freeglut
AC_CHECK_LIB([GL], [glBegin])
AC_CHECK_LIB([glut], [glutInit])
AC_CHECK_LIB([GLU], [gluPerspective])
AC_CHECK_LIB([SDL2], [SDL_Init])

#put autoconf files in it's own directory
AC_CONFIG_AUX_DIR(build-aux)

#ENABLE AUTOMAKE TO SIMPLIFY MAKEFILES
AM_INIT_AUTOMAKE([1.11 subdir-objects -Wall -Werror])

AC_CONFIG_FILES(Makefile)

AC_PROG_CXX

#FINAL OUTPUT
AC_OUTPUT
