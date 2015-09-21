#pragma once
/*H**********************************************************************
 * FILENAME :        SnakeGame.h
 *
 * DESCRIPTION :
 *       Contains the entire game.
 *
 * PUBLIC FUNCTIONS :
 *       void run(); //main game loop
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

#include <stdlib.h>
#include <SDL2/SDL.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include "Arena.hpp"
#include "Game.hpp"

extern unsigned int screen_dim;
extern unsigned int snake_dir;

class SnakeGame : public Game {

 public:
  SnakeGame();
  virtual ~SnakeGame();
  void run();

 private:
  Arena arena;
  void keyboard(const SDL_Event &event);
};
