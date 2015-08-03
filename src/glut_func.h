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
#include <GL/freeglut.h>
#include <GL/glu.h>
#include <stdio.h>
#include <stdbool.h>

#include "arena.h"

#ifndef GLUT_FUNC_H_INCLUDED
#define GLUT_FUNC_H_INCLUDED

extern unsigned int screen_dim;

void idle(void);
void display(void);
void keyboard(unsigned char key, int x, int y);
void mouse(int button, int state, int x, int y);
void reshape(GLsizei width, GLsizei height);

#endif //GLUT_FUNC_H_INCLUDED
