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

#ifndef ARENA_H_INCLUDED
#define ARENA_H_INCLUDED

extern unsigned int snake_x;
extern unsigned int snake_y;
extern unsigned int snake_dir;

void update_arena(void);

#endif //ARENA_H_INCLUDED
