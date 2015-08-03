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

unsigned int arena[20][20];
unsigned int snake_dir;
extern unsigned int screen_dim;

void update_arena(void);
void update_snake(void);
void is_snake_dead(void);

#endif //ARENA_H_INCLUDED
