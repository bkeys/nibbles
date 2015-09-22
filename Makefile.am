bin_PROGRAMS = snake

#files of project
snake_SOURCES = src/main.cpp src/Arena.cpp src/Arena.hpp src/SnakeGame.cpp src/SnakeGame.hpp src/Game.hpp src/Game.cpp src/Snake.hpp src/Snake.cpp src/Element.hpp src/Element.cpp src/Fruit.hpp src/Fruit.cpp src/Obstacle.cpp src/Obstacle.hpp

AM_CXXFLAGS = -pedantic -O3 -std=c++11 -Werror -g

#using an m4 directory for macros
ACLOCAL_AMFLAGS = -I m4 --install

#letting autoconf know about the m4 dir
EXTRA_DIST = m4/NOTES
