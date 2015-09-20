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

#include <GL/freeglut.h>
#include <GL/glu.h>

#include "arena.h"

extern unsigned int screen_dim;
extern unsigned int snake_dir;

class FreeGlut {

 public:
  FreeGlut();
  ~FreeGlut();
  
 private:
  static void idle(void);
  static void display(void);
  static void keyboard(unsigned char key, int x, int y);
  static void mouse(int button, int state, int x, int y);
  static void reshape(GLsizei width, GLsizei height);
  static void special(int key, int x, int y);
  static void timer(int value);
};
