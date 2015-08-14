#include <stdio.h>

#include "arena.h"

#define SNAKE_UP     1
#define SNAKE_DOWN   2
#define SNAKE_LEFT   3
#define SNAKE_RIGHT  4

bool is_init  = true;
unsigned int snake_length;

node *cursor;

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

  switch(snake_dir) {

  case SNAKE_UP:
    snake.y++;
    break;

  case SNAKE_DOWN:
    snake.y--;
    break;

  case SNAKE_LEFT:
    snake.x--;
    break;

  case SNAKE_RIGHT:
    snake.x++;
    break;
  }
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

  snake_length  = 4;
  snake_dir     = 1 + (rand() % 4);
  snake.x       = rand() % 20;
  snake.y       = rand() % 20;
  cursor        = &snake;

  for(int i  = 0; i < snake_length; ++i) {

    cursor->next = (node*)calloc(sizeof(node), 1);

    //    cursor->next->prev = cursor;

    // Increment cursor
    cursor = cursor->next;

    // Assign data in linked list
    //    cursor->x = (cursor->prev->x) + 1;
    //    cursor->y = (cursor->prev->y) + 1;


  
  }

  cursor->next  = NULL;
    cursor  = &snake;

  while(cursor->next) {
    fprintf(stdout, "This node has:\n\tX: %d\n\tY: %d\n", cursor->x, cursor->y);
	cursor = cursor->next;
  }
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

  if(snake.x > 20 || snake.x < 0 || snake.y > 20 || snake.y < 0) {
    return true;
  }
  return false;
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
      if(snake.x == x && snake.y == z) {
	glColor3f(0, 0, 255);
      }

      while(cursor->next) {
	if(cursor->x == x && cursor->y == z) {
	  glColor3f(0, 0, 255);
	}
	cursor  = cursor->next;
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
    is_init  = false;
  }

  update_snake();
  draw_arena();
}
