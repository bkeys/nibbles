#pragma once
/*H***********************************************************
 * FILENAME :        Snake.hpp
 *
 * DESCRIPTION :
 *       Contains the snake and it's body.
 *       
 *       
 *       
 *
 * PUBLIC FUNCTIONS :
 *         updates the snakes location in the arena
 *         void update(void);
 *         
 *         draws the snake onto the screen
 *         void draw(void);
 *         
 *         grows the snake to a specified size
 *         void grow(int size);
 *         
 *         sets the snake's direction
 *         void setDir(Dir direction);
 *
 * AUTHOR     :    Brigham Keys, Esq
 * START DATE :    09/20/2015
 *
 *H*/

#include <iostream>
#include <list>
#include <GL/gl.h>
#include <GL/freeglut.h>
#include "Element.hpp"

enum Dir {UP, DOWN, RIGHT, LEFT};

class Body : public Element {

public:
  void draw() {
    glColor3ub(0, 0, 255);
    glPushMatrix();
    glTranslatef(x, y, -y);
    glutSolidCube(1);
    glPopMatrix();
  }
};

class Snake {

public:
  Snake();
  ~Snake();
  void update(void);
  void draw(void);
  void grow(int size);
  void setDir(Dir direction);
  std::list<Body> body;
  std::list<Body>::iterator i;
  
private:
  Dir dir;
};
