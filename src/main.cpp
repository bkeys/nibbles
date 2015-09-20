#ifdef __MINGW32__
#include <windows.h>
#endif

#ifdef WIN32
#include <windows.h>
#endif

#include <GL/freeglut.h>
#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include <time.h>
#include "FreeGlut.h"

/*F******************************************************************
 * main(int argc, char **argv)
 * 
 * PURPOSE : entry into the program
 *
 * RETURN :  int
 *
 * NOTES :   Best viewed with emacs
 *F*/
int main(int argc, char **argv) {

  srand(time(NULL));
  FreeGlut f;

  glutMainLoop();
  return EXIT_SUCCESS;
}
