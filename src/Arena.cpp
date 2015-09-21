#include <stdio.h>

#include "Arena.hpp"

#define SNAKE_UP     1
#define SNAKE_DOWN   2
#define SNAKE_LEFT   3
#define SNAKE_RIGHT  4

unsigned int snake_x;
unsigned int snake_y;
unsigned int snake_dir;

typedef struct {
  int x;
  int y;
} point;

bool is_init  = true;
unsigned int snake_length;
unsigned int obstacle_amount;

point *snake_body;
point *obstacle_points;

/*F******************************************************************
 * init_obstacle(void)
 * 
 * PURPOSE : creates obstacles in the map
 *           
 * RETURN :  void
 *
 * NOTES :   
 *F*/
void init_obstacle(void) {

  obstacle_amount  = rand() % 5;
  obstacle_points  = (point*)calloc(obstacle_amount, sizeof(point));
  for(int i  = 0; i < obstacle_amount; ++i) {
    obstacle_points[i].x  =  rand() % 20;
    obstacle_points[i].y  =  (rand() % 20) - 1;
  }
}

/*F******************************************************************
 * update_snake(void)
 * 
 * PURPOSE : enables the snake to move according to the direction it
 *           is currently facing
 *
 * RETURN :  void
 *
 * NOTES :   
 *F*/
void update_snake(void) {

  for(int i  = snake_length; i > 0; --i) {
    snake_body[i]  = snake_body[i - 1];
  }
  switch(snake_dir) {

  case SNAKE_UP:
    snake_body[0].y++;
    break;

  case SNAKE_DOWN:
    snake_body[0].y--;
    break;

  case SNAKE_LEFT:
    snake_body[0].x--;
    break;

  case SNAKE_RIGHT:
    snake_body[0].x++;
    break;
  }
}

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

  if(snake_body[0].x == fruit->getX() && snake_body[0].y == fruit->getY()) {
    return true;
  }
  return false;  
}

/*F******************************************************************
 * init_snake(void)
 * 
 * PURPOSE : places the snake randomly in the arena and sets it's length
 *
 * RETURN :  void
 *
 * NOTES :   this might not need to be a function at all, it only
 *           gets called once, check at the end of the project, if
 *           it only gets called once it probably should not be a function
 *           We also might want to check to see if the snake is on the edge
 *           or is close to the edge and facing the edge, the #defines
 *           should come in handy for this purpose
 *F*/
inline void init_snake() {

  snake_length     = 4;
  snake_body       = (point*)calloc(sizeof(point), snake_length);
  snake_dir        = 1 + (rand() % 4);
  bool is_snake_init;

  snake_body[0].x  = rand() % 20;
  snake_body[0].y  = (rand() % 20) - 1;
  is_snake_init  = true;
  
  for(int i  = 0; i < obstacle_amount; ++i) {
    if(obstacle_points[i].x == snake_body[0].x &&
       obstacle_points[i].y == snake_body[0].y) {
      is_snake_init  = false;
    }
  }
  /*
    if(snake_body[0].x != fruit.x || snake_body[0].y != fruit.y) {
    is_snake_init  = false;
    }
  */

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
inline bool is_snake_dead(void) {

  bool is_dead  = false;
  
  //if the snake collided with an object
  for(int i  = 0; i < obstacle_amount; ++i) {
    if(obstacle_points[i].x == snake_body[0].x && obstacle_points[i].y == snake_body[0].y) {
      is_dead  = true;
    }
  }

  //if the snake collided with itself
  for(int i  = 1; i < snake_length; ++i) {
    if(snake_body[i].x == snake_body[0].x && snake_body[i].y == snake_body[0].y) {
      is_dead  = true;
    }
  }

  //if the snake ran out of the arena
  if(snake_body[0].x >= 20 || snake_body[0].x < 0 || snake_body[0].y >= 20 || snake_body[0].y == -1) {
    is_dead  = true;
  }

  if(is_dead) {
    if(snake_body != NULL) {
      free(snake_body);
    }
    if(obstacle_points != NULL) {
      free(obstacle_points);
    }
  }
  return is_dead;
}

/*F******************************************************************
 * draw_square(void)
 * 
 * PURPOSE : draws the square of each element in the arena
 *
 * RETURN :  void
 *
 * NOTES :   
 *F*/
inline void draw_square(int x, int y, bool element) {

  if(element) {
    glPushMatrix();
    glTranslatef(x, y, -y);
    glutSolidCube(1);
    glPopMatrix();
  } else {
  
    glColor4f(.1, .2, .3, .3);
    glPushMatrix();
    glTranslatef(x, y - 1, -y);
    glutSolidCube(1);
    glPopMatrix();
  }
    
}

/*F******************************************************************
 * draw_square(void)
 * 
 * PURPOSE : draws the square of each element in the arena
 *
 * RETURN :  void
 *
 * NOTES :   
 *F*/
inline void draw_obstacle(int x, int y, bool element) {

  if(element) {
    glPushMatrix();
    glTranslatef(x, y, -y);
    glutSolidTeapot(.7);
    glPopMatrix();
  } else {
    glColor4f(.1, .2, .3, .3);
    glPushMatrix();
    glTranslatef(x, y - 1, -y);
    glutSolidCube(1);
    glPopMatrix();
  }
    
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

  for(int x  = 0; x < 20; ++x) {
    for(int y  = 0; y < 20;++y) {
      
      //drawing the snake's location
      for(int i  = 0; i < snake_length; ++i) {
	if(snake_body[i].x == x && snake_body[i].y == y) {
	  glColor3ub(0, 0, 255);
	  draw_square(x, y, true);
	}
      }

      //drawing the obstacle location
      for(int i  = 0; i < obstacle_amount; ++i) {
	if(obstacle_points[i].x == x && obstacle_points[i].y == y) {
	  glColor3ub(0, 255, 0);
	  draw_obstacle(x, y, true);
	}
      }

      draw_square(x, y, false);
    }
  }
  fruit->draw();

  glFlush();
  glFinish();
}

Arena::Arena() {
  fruit = new Fruit();
}

Arena::~Arena() {


}

/*F******************************************************************
 * update_arena(void)
 * 
 * PURPOSE : delegates the work of the arena
 *
 * RETURN :  void
 *
 * NOTES :   
 *F*/
void Arena::update_arena(void) {

  if(is_init || is_snake_dead()) {
    init_snake();
    init_obstacle();
    is_init  = false;
  }

  if(is_snake_eating()) {
    delete[] fruit;
    fruit = new Fruit();
    snake_length += 2;
    snake_body    = (point*)realloc(snake_body, snake_length * sizeof(point));
  }

  update_snake();

  draw();
}