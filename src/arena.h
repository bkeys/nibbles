/*H**********************************************************************
 * FILENAME :        glut_func.h
 *
 * DESCRIPTION :
 *       All our glut functions that are in the event processing loop
 *
 * PUBLIC FUNCTIONS :
 *       void idle(void);
 *       void display(void);
 *       void keyboard(unsigned char key, int x, int y);
 *       void mouse(int button, int state, int x, int y);
 *       
 *
 * AUTHOR     :    Brigham Keys, Esq
 * START DATE :    07/31/2015
 *
 *H*/
#ifndef ARENA_H_INCLUDED
#define ARENA_H_INCLUDED

#ifdef __MINGW32__
#include <windows.h>
#endif

#ifdef WIN32
#include <windows.h>
#endif

#include <GL/gl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  int x;
  int y;

  struct node *next;
} node;

node snake;

unsigned int snake_dir;

void update_arena(void);

#endif //ARENA_H_INCLUDED
