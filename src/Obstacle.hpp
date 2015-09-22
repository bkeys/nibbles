#pragma once
/*H**********************************************************************
 * FILENAME :        Obstacle.hpp
 *
 * DESCRIPTION :
 *       A snake can run into an obstacle and it will cause the snake
 *       to die and the game to restart
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
#include "Element.hpp"

class Obstacle : public Element {

public:
  Obstacle();
  void draw(void);
};
