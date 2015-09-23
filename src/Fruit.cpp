#include "Fruit.hpp"

/*F***********************************************************
 * draw(void)
 * 
 * PURPOSE : Draws the fruit onto the screen
 *
 * RETURN :  
 *
 * NOTES :   
 *F*/
void Fruit::draw() {

  glColor3ub(255, 0, 0);
  glPushMatrix();
  glTranslatef(x, y, -y);
  glutSolidSphere(.7, 20, 20);
  glPopMatrix();
}
