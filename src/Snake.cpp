#include "Snake.hpp"

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
 * setDir(Dir direction)
 * 
 * PURPOSE : Sets the direction of the snake
 *
 * RETURN :  void
 *
 * NOTES :   
 *F*/
void Snake::setDir(Dir direction) {

  switch(dir) {

  case UP:
    if(direction == DOWN)
      return;
    dir = direction;
    break;
    
  case DOWN:
    if(direction == UP)
      return;
    dir = direction;
    break;
    
  case RIGHT:
    if(direction == LEFT)
      return;
    dir = direction;
    break;
    
  case LEFT:
    if(direction == RIGHT)
      return;
    dir = direction;
    break;
  }
}

/*F******************************************************************
 * grow(int size)
 * 
 * PURPOSE : Grows the snake longer to a specific size. The snake 
 *           cannot be shrunk
 *
 * RETURN :  void
 *
 * NOTES :   
 *F*/
void Snake::grow(int size) {


}

/*F******************************************************************
 * snake(void)
 * 
 * PURPOSE : enables the snake to move according to the direction it
 *           is currently facing
 * 
 * RETURN :  void
 *
 * NOTES :   
 *F*/
void Snake::update(void) {
  
  switch(dir) {

  case UP:
    break;

  case DOWN:
    break;

  case LEFT:
    break;

  case RIGHT:
    break;

  default:// throw an error
    break;
  }
}

/*F******************************************************************
 * DEFAULT CONSTRUCTOR
 * 
 * NOTES :   
 *F*/
Snake::Snake() {

  dir = UP;

  grow(3);
}

/*F******************************************************************
 * DESTRUCTOR
 * 
 * NOTES :   
 *F*/
Snake::~Snake() {
  
}

/*F******************************************************************
 * draw(void)
 * 
 * PURPOSE : draws the entire snake body onto the screen 
 *
 * RETURN :  void 
 *
 * NOTES :   
 *F*/
void Snake::draw(void) {
  
  
}
