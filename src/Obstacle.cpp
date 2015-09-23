#include "Obstacle.hpp"

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
 * NOTES :   
 *F*/
Obstacle::Obstacle() {
  iter = item.begin();
  for(int j = 0; j < 5; ++j) {
    Item b;
    item.push_back(b);
  }
}

/*F***********************************************************
 * draw(void)
 * 
 * PURPOSE : Draws the obstacle onto the screen
 *
 * RETURN :  
 *
 * NOTES :   
 *F*/
void Obstacle::draw(void) {
  for(iter = item.begin(); iter != item.end();++iter) {
    (*iter).draw();
  }
}
