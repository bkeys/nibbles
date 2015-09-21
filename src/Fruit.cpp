#include "Fruit.hpp"

/*F******************************************************************
 * init_fruit(void)
 * 
 * PURPOSE : Places the fruit on the map after it has been eaten, or
 *           the player has died. It also handles the fruit so that
 *           it does not spawn on top of the snake or obstacles
 *
 * RETURN :  void
 *
 * NOTES :   
 *F*/
Fruit::Fruit() {

  x  = rand() % 20;
  y  = (rand() % 20);

}

/*F******************************************************************
 * 
 * 
 * PURPOSE : 
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
