bin_PROGRAMS = snake

#files of project
snake_SOURCES = src/main.cpp src/arena.cpp src/arena.h src/FreeGlut.cpp src/FreeGlut.h

AM_CXXFLAGS = -pedantic -O3 -std=c++11 -Werror

#using an m4 directory for macros
ACLOCAL_AMFLAGS = -I m4 --install

#letting autoconf know about the m4 dir
EXTRA_DIST = m4/NOTES
