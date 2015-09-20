#pragma once
/*H**********************************************************************
 * FILENAME :        glut_func.h
 *
 * DESCRIPTION :
 *       All our glut functions that are in the event processing loop
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

#include <SDL2/SDL.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include "arena.h"

extern unsigned int screen_dim;
extern unsigned int snake_dir;

class SnakeGame {

 public:
  SnakeGame();
 ~SnakeGame();
  void main_loop();
  void idle(void);
  void display(void);
  void keyboard(const SDL_Event &event);
  void reshape(GLsizei width, GLsizei height);
  void special(int key, int x, int y);
 private:
  Arena arena;
  
};
