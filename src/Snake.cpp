#include "Snake.hpp"

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
    if(direction == DOWN) return;
    dir = direction;
    return;
    
  case DOWN:
    if(direction == UP) return;
    dir = direction;
    return;
    
  case RIGHT:
    if(direction == LEFT) return;
    dir = direction;
    return;
    
  case LEFT:
    if(direction == RIGHT) return;
    dir = direction;
    return;

  default:

    return;
  }
}

/*F***********************************************************
 * grow(int size)
 * 
 * PURPOSE : Grows the snake longer to a specific size. The
 *           snake cannot be shrunk
 *
 * RETURN :  void
 *
 * NOTES :   
 *F*/
void Snake::grow(int size) {

  i = body.begin();
  for(int j = 0; j < size; ++j) {
    Body b;
    b.setX((*i).getX());
    b.setY((*i).getY());
    body.push_back(b);
  }
}

/*F***********************************************************
 * snake(void)
 * 
 * PURPOSE : enables the snake to move according to
 *           the direction it is currently facing
 * 
 * RETURN :  void
 *
 * NOTES :   
 *F*/
void Snake::update(void) {

  i = body.begin();
  int tempx = (*i).getX();
  int tempy = (*i).getY();

  Body e;
  body.push_front(e);
  body.pop_back();

  i = body.begin();
  (*i).setX(tempx);
  (*i).setY(tempy);

  switch(dir) {

  case UP:
    (*i).setY((*i).getY() + 1);
    return;

  case DOWN:
    (*i).setY((*i).getY() - 1);
    return;

  case LEFT:
    (*i).setX((*i).getX() - 1);
    return;

  case RIGHT:
    (*i).setX((*i).getX() + 1);
    return;

  default:// throw an error
    std::cout << "error involving dir" << std::endl;
    return;
  }
}

/*F***********************************************************
 * DEFAULT CONSTRUCTOR
 * 
 * NOTES :   
 *F*/
Snake::Snake() {

  dir = UP;
  i = body.begin();
  grow(4);
}

/*F***********************************************************
 * DESTRUCTOR
 * 
 * NOTES :   
 *F*/
Snake::~Snake() {
  
}

/*F***********************************************************
 * draw(void)
 * 
 * PURPOSE : draws the entire snake body onto the screen 
 *
 * RETURN :  void 
 *
 * NOTES :   
 *F*/
void Snake::draw(void) {

  for(i = body.begin(); i != body.end();++i) {
    (*i).draw();
  }
}
