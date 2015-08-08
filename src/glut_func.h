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
#ifndef GLUT_FUNC_H_INCLUDED
#define GLUT_FUNC_H_INCLUDED

#ifdef __MINGW32__
#include <windows.h>
#endif

#ifdef WIN32
#include <windows.h>
#endif

#include <GL/freeglut.h>
#include <GL/glu.h>
#include <stdio.h>
#include <stdbool.h>

#include "arena.h"

extern unsigned int screen_dim;
unsigned int snake_x;
unsigned int snake_y;
unsigned int snake_dir;

void idle(void);
void display(void);
void keyboard(unsigned char key, int x, int y);
void mouse(int button, int state, int x, int y);
void reshape(GLsizei width, GLsizei height);
void special(int key, int x, int y);
void timer(int value);

#endif //GLUT_FUNC_H_INCLUDED
