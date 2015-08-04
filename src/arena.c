#include "arena.h"

#define SNAKE_UP     1
#define SNAKE_DOWN   2
#define SNAKE_LEFT   3
#define SNAKE_RIGHT  4

bool is_init  = true;
unsigned int snake_length;

struct Snake_Tail{
  int *x;
  int *y;
} tail;

unsigned int snake_length;

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
    snake_y++;
    break;

  case SNAKE_DOWN:
    snake_y--;
    break;

  case SNAKE_LEFT:
    snake_x--;
    break;

  case SNAKE_RIGHT:
    snake_x++;
    break;
  }

  tail.x[3]  = snake_x;
  tail.y[3]  = snake_y;
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
 *F*/
inline void init_snake() {

  snake_length  = 4;
  tail.x        = calloc(sizeof(int), snake_length);
  tail.y        = calloc(sizeof(int), snake_length);
  snake_x       = rand() % 20;
  snake_y       = rand() % 20;
  snake_length  = 4;
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

  if(snake_x > 20 || snake_y > 20) {
    free(tail.x);
    free(tail.y);
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
      if(snake_x == x && snake_y ==z) {
	glColor3f(0, 0, 255);
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
