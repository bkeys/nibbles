#include "arena.h"

/*F******************************************************************
 * update_arena(void)
 * 
 * PURPOSE : 
 *
 * RETURN :  
 *
 * NOTES :   
 *F*/
void update_arena(void) {

  
  glColor3f(0.1, 0.2, 0.3);

  for(int x  = 0; x < 20; ++x) {
    for(int z  = 0; z < 20; ++z) {
      glBegin(GL_TRIANGLES);
      glVertex3f(x - 10      , -2, (-5 + z) - 20); //--
      glVertex3f((x + 1) - 10, -2, (-5 + z) - 20); //+-
      glVertex3f(x - 10      , -2, (-4 + z) - 20); //-+
      glEnd();
    }
  }
  glRotatef(30, 0, 1, 0);
}

/*F******************************************************************
 * update_snake(void)
 * 
 * PURPOSE : 
 *
 * RETURN :  
 *
 * NOTES :   
 *F*/
void update_snake(void) {

  
}

/*F******************************************************************
 * is_snake_dead(void)
 * 
 * PURPOSE : 
 *
 * RETURN :  
 *
 * NOTES :   
 *F*/
void is_snake_dead(void) {

  

}
