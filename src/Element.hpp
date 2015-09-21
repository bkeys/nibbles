#pragma once
/*H**********************************************************************
 * FILENAME :        Element.h
 *
 * DESCRIPTION :
 *       Abstract class that is used for all elements inside of the arena
 *       
 *       
 *       
 *
 * PUBLIC FUNCTIONS :
 *       
 *
 * AUTHOR     :    Brigham Keys, Esq
 * START DATE :    09/20/2015
 *
 *H*/

class Element {

public:
  Element();
  virtual void draw() = 0;
  int getX();
  int getY();
  void setX(int it);
  void setY(int it);

protected:
  int x;
  int y;
};
