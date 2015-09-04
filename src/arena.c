#include <stdio.h>

#include "arena.h"

#define SNAKE_UP     1
#define SNAKE_DOWN   2
#define SNAKE_LEFT   3
#define SNAKE_RIGHT  4

typedef struct {
  int x;
  int y;
} point;

bool is_init  = true;
unsigned int snake_length;
unsigned int obstacle_amount;

unsigned int fruit_x;
unsigned int fruit_y;
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
    obstacle_points[i].y  =  rand() % 20;
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
inline bool is_snake_eating(void) {

  if(snake_body[0].x == fruit_x && snake_body[0].y == fruit_y) {
    return true;
  }
  return false;  
}

/*F******************************************************************
 * init_fruit(void)
 * 
 * PURPOSE : Places the fruit on the map after it has been eaten, or
 *           the player has died
 *
 * RETURN :  void
 *
 * NOTES :   
 *F*/
inline void init_fruit(void) {
  fruit_x  = rand() % 20;
  fruit_y  = rand() % 20;
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
  snake_body[0].x  = rand() % 20;
  snake_body[0].y  = rand() % 20;

  init_fruit();
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
  
  for(int i  = 0; i < obstacle_amount; ++i) {
    if(obstacle_points[i].x == snake_body[0].x && obstacle_points[i].y == snake_body[0].y) {
      is_dead  = true;
    }
  }


  for(int i  = 1; i < snake_length; ++i) {
    if(snake_body[i].x == snake_body[0].x && snake_body[i].y == snake_body[0].y) {
      is_dead  = true;
    }
  }

  if(snake_body[0].x > 20 || snake_body[0].x < 0 || snake_body[0].y > 20 || snake_body[0].y < 0) {
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
 * draw_arena(void)
 * 
 * PURPOSE : draws the arena to the buffer
 *
 * RETURN :  void
 *
 * NOTES :   
 *F*/
void draw_arena() {

  glBegin(GL_QUADS);
  for(int x  = 0; x < 20; ++x) {
    for(int z  = 0; z < 20;++z) {

      glColor4f(.1, .2, .3, .3);

      //drawing the snake's location
      for(int i  = 0; i < snake_length; ++i) {
	if(snake_body[i].x == x && snake_body[i].y == z) {
	  glColor3f(0, 0, 255);
	}
      }

      for(int i  = 0; i < obstacle_amount; ++i) {
	if(obstacle_points[i].x == x && obstacle_points[i].y == z) {
	  glColor3f(0, 255, 0);
	}
      }

      if(fruit_x == x && fruit_y == z) {
	glColor3f(255, 0, 0);
      }

      glVertex3f(x - 9,
		 z - 6,
		 -z - 14); //+-
      glVertex3f(x - 10,
		 z - 6,
		 -z - 14); //--
      glVertex3f(x - 10,
		 (z + 1) - 6,
		 -z - 15); //++
      glVertex3f(x - 9,
		 (z + 1) - 6,
		 -z - 15); //-+
    }
  }
  glEnd();

  glFlush();
  glFinish();
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
void update_arena(void) {

  if(is_init || is_snake_dead()) {
    init_snake();
    init_obstacle();
    is_init  = false;
  }

  if(is_snake_eating()) {
    init_fruit();
    snake_length += 2;
    snake_body    = (point*)realloc(snake_body, snake_length * sizeof(point));
  }

  update_snake();
  draw_arena();
}
