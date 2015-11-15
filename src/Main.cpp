#ifdef __MINGW32__
#include <windows.h>
#endif

#ifdef WIN32
#include <windows.h>
#endif

#include <time.h>
#include <GL/freeglut.h>
#include <SDL2/SDL.h>
#include "SnakeGame.hpp"

/*F******************************************************************
 * main(int argc, char **argv)
 * 
 * PURPOSE : entry into the program
 *
 * RETURN :  int
 *
 * NOTES :   Best viewed with emacs
 *F*/
int main(int argc, char *argv[]) {

  srand(time(NULL));
  
  SnakeGame *f = new SnakeGame();
  f->run();
  return 0;
}
