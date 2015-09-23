#include "Element.hpp"

/*F***********************************************************
 * 
 * 
 * PURPOSE : 
 *
 * RETURN :  
 *
 * NOTES :   
 *F*/

/*F***********************************************************
 * DEFAULT CONSTRUCTOR
 * 
 * PURPOSE : This constructor is very simple and should not
 *           really be used it is simply here as a fallback
 *
 * NOTES :   
 *F*/
Element::Element() {
  x = rand() % 20;
  y = rand() % 20 - 1;
}

/*F***********************************************************
 * draw()
 * 
 * PURPOSE : draws this onto the screen
 *
 * RETURN :  void
 *
 * NOTES :   
 *F*/
void Element::draw() {

}

/*F***********************************************************
 * getX()
 * 
 * RETURN :  int (x)
 *
 * NOTES :   
 *F*/
int Element::getX() {
  return x;
}

/*F***********************************************************
 * getY()
 * 
 * RETURN :  int (y)
 *
 * NOTES :   
 *F*/
int Element::getY() {
  return y;
}

/*F***********************************************************
 * setX(int it)
 * 
 * RETURN :  void
 *
 * NOTES :   
 *F*/
void Element::setX(int it) {
  x = it;
}

/*F***********************************************************
 * setY(int it)
 * 
 * RETURN :  void
 *
 * NOTES :   
 *F*/
void Element::setY(int it) {
  y = it;
}

