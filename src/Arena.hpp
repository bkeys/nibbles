#pragma once
/*H**********************************************************************
 * FILENAME :        arena.h
 *
 * DESCRIPTION :
 *       Contains main game content and holds the contents of the arena
 *       such as the snake, fruit, and obstacles
 *
 * PUBLIC FUNCTIONS :
 *       update_arena(void)
 *
 * AUTHOR     :    Brigham Keys, Esq
 * START DATE :    07/31/2015
 *
 *H*/
#ifdef __MINGW32__
#include <windows.h>
#endif

#ifdef WIN32
#include <windows.h>
#endif

#include <GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h>

#include "Obstacle.hpp"
#include "Fruit.hpp"
#include "Snake.hpp"

class Arena {

 public:

  Arena();
  virtual ~Arena();
  void update_arena(void);
  void draw(void);

 private:
  bool is_snake_eating(void);
  Obstacle *obs;
  Fruit *fruit;
  Snake *snake;
  
};
