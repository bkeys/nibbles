#include "Arena.hpp"

/*F******************************************************************
 * is_snake_eating(void)
 * 
 * PURPOSE : Determines collision between the snake and the fruit
 *           
 *
 * RETURN :  bool
 *
 * NOTES :   
 *F*/
bool Arena::is_snake_eating(void) {

}

/*F******************************************************************
 * is_snake_dead(void)
 * 
 * PURPOSE : inline function that checks if the snake is dead
 *
 * RETURN :  bool, true if dead, false if not
 *
 * NOTES :   needs to be expanded later to ensure the snake can collide
 *           with itself
 *F*/
bool Arena::is_snake_dead(void) {

}

/*F******************************************************************
 * draw(void)
 * 
 * PURPOSE : draws the arena to the buffer
 *
 * RETURN :  void
 *
 * NOTES :   
 *F*/
void Arena::draw(void) {

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  //drawing the floor
  for(int x  = 0; x < 20; ++x) {
    for(int y  = 0; y < 20;++y) {
      glColor4f(.1, .2, .3, .3);
      glPushMatrix();
      glTranslatef(x, y - 1, -y);
      glutSolidCube(1);
      glPopMatrix();
    }
  }

  snake->draw();
  obstacle->draw();
  fruit->draw();

  glFlush();
  glFinish();
}

Arena::Arena() {
  snake    = new Snake();
  obstacle = new Obstacle();
  fruit    = new Fruit();
}

Arena::~Arena() {
  if(snake != NULL) {
    delete[] snake;
  }
  if(obstacle != NULL) {
    delete[] obstacle;
  }
  if(fruit != NULL) {
    delete[] fruit;
  }
}

/*F******************************************************************
 * update_arena(void)
 * 
 * PURPOSE : checks all possible events that could of occured in the
 *           arena
 *
 * RETURN :  void
 *
 * NOTES :   
 *F*/
void Arena::update(void) {

  snake->update();
  draw();
}
