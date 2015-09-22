#include "Obstacle.hpp"

/*F******************************************************************
 * 
 * 
 * PURPOSE : 
 *
 * RETURN :  
 *
 * NOTES :   
 *F*/

/*F******************************************************************
 * DEFAULT CONSTRUCTOR
 * 
 * NOTES :   
 *F*/
Obstacle::Obstacle() {
  x = rand() % 20;
  y = (rand() % 20) -1;
}

/*F******************************************************************
 * draw(void)
 * 
 * PURPOSE : Draws the obstacle onto the screen
 *
 * RETURN :  
 *
 * NOTES :   
 *F*/
void Obstacle::draw(void) {
  glColor3ub(0, 255, 0);
  glPushMatrix();
  glTranslatef(x, y, -y);
  glutSolidTeapot(.7);
  glPopMatrix();
}
