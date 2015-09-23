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

  iter = body.begin();
  for(int j = 0; j < size; ++j) {
    Body b;
    b.setX((*iter).getX());
    b.setY((*iter).getY());
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

  iter = body.begin();
  int tempx = (*iter).getX();
  int tempy = (*iter).getY();

  Body e;
  body.push_front(e);
  body.pop_back();

  iter = body.begin();
  (*iter).setX(tempx);
  (*iter).setY(tempy);

  switch(dir) {

  case UP:
    (*iter).setY((*iter).getY() + 1);
    return;

  case DOWN:
    (*iter).setY((*iter).getY() - 1);
    return;

  case LEFT:
    (*iter).setX((*iter).getX() - 1);
    return;

  case RIGHT:
    (*iter).setX((*iter).getX() + 1);
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

  

  switch(rand() % 4) {
  case 0:
    dir = UP;
    break;

  case 1:
    dir = DOWN;
    break;

  case 2:
    dir = RIGHT;
    break;

  case 3:
    dir = LEFT;
    break;
  }

  iter = body.begin();
  Body b;
  b.setX(rand() % 20);
  b.setY(rand() % 20 - 1);
  body.push_back(b);

  grow(3);

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

  for(iter = body.begin(); iter != body.end();++iter) {
    (*iter).draw();
  }
}
