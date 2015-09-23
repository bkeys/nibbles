#pragma once
/*H*********************************************************** * FILENAME :        Element.h
 *
 * DESCRIPTION :
 *       Abstract class that is used for all elements inside
 *       of the arena
 *       
 *       
 *       
 *
 * PUBLIC FUNCTIONS :
 *       getX()
 *       setX()
 *       getY()
 *       setY()
 *
 * AUTHOR     :    Brigham Keys, Esq
 * START DATE :    09/20/2015
 *
 *H*/

#include <iostream>
#include <ostream>
#include <GL/freeglut.h>
#include <GL/gl.h>

class Element {

public:
  Element();
  virtual void draw() = 0;
  int getX();
  int getY();
  void setX(int it);
  void setY(int it);
  void display();

protected:
  int x;
  int y;
};
