#pragma once
/*H**********************************************************************
 * FILENAME :        Game.h
 *
 * DESCRIPTION :
 *       Universal abstract game class. Class contains the basic elements
 *       of all games that I create. That being an SDL2 window, FreeGlut
 *       funcitonality and OpenGL 3D capabilities. This class is abstract
 *       and is to be inherited from.
 *
 * PUBLIC FUNCTIONS :
 *       void run(); //The main game loop
 *
 * AUTHOR     :    Brigham Keys, Esq
 * START DATE :    09/20/2015
 *
 *H*/

#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>

class Game {

 public:
  Game();
  ~Game();
  virtual void run()=0;
  int get_score();
  void set_score(int s);
 private:

 protected:
  unsigned int score;
  SDL_Renderer* displayRenderer;
  SDL_Window* displayWindow;
  SDL_RendererInfo displayRendererInfo;

};

