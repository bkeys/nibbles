#include "SnakeGame.h"

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
 * DEFAULT CONSTRUCTOR
 *
 * NOTES :   
 *F*/
SnakeGame::SnakeGame() {

  char fakeParam[] = "fake";
  char *fakeargv[] = { fakeParam, NULL };
  int fakeargc = 1;
  glutInit(&fakeargc, fakeargv);

  /*---- initialization -------------------------------------------------*/
  glEnable(GL_BLEND);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_COLOR_MATERIAL);
  glDepthFunc(GL_LEQUAL);
  glShadeModel(GL_SMOOTH);
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  glClearColor (0.0, 0.0, 0.0, 0.0);
  glShadeModel (GL_SMOOTH);

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_NORMALIZE);
  //moving the matrix back
  glTranslatef(-7.0f, 0.0f, -60);
  /*---------------------------------------------------------------------*/

  /*setting up viewport*/
  int width  = 800;
  int height = 600;

  /* Height / width ration */
  GLfloat ratio;

  /* Protect against a divide by zero */
  if (height == 0) {
    height = 1;
  }

  ratio = (GLfloat)width / (GLfloat)height;

  glViewport(0, 0, (GLsizei)width, (GLsizei)height);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluPerspective(45.0f, ratio, 0.1f, 100.0f);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

}

/*F******************************************************************
 * DESTRUCTOR
 * 
 * NOTES :   
 *F*/
SnakeGame::~SnakeGame() {
  SDL_Quit();
}

/*F******************************************************************
 * reshape(GLsizei width, GLsizei height)
 * 
 * PURPOSE : Our glutReshapeFunc, enables the window to be resized
 *
 * RETURN :  void
 *
 * NOTES :   
 *F*/
void SnakeGame::reshape(GLsizei width, GLsizei height) {

  GLfloat aspect = (GLfloat)width / (GLfloat)height;

  if(height == 0) {
    height = 1;
  }

  glViewport(0, 0, width, height);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluPerspective(45.0f, aspect, 0.1f, 100.0f);
  glFlush();
  glFinish();
}

/*F******************************************************************
 * display(void)
 * 
 * PURPOSE : Our glutDisplayFunc, draws our arena onto the screen
 *
 * RETURN :  void
 *
 * NOTES :   
 *F*/
void SnakeGame::display(void) {

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  arena.update_arena();
  glFlush();
  glFinish();
}

/*F******************************************************************
 * keyboard(unsigned char key, int x, int y)
 * 
 * PURPOSE : our glutKeyboardFunc, it enables the user to exit the game
 *
 * RETURN :  void
 *
 * NOTES :   
 *F*/
void SnakeGame::keyboard(const SDL_Event &event) {

  switch(event.key.keysym.scancode) {

  case SDL_SCANCODE_W:
    if(snake_dir == 2) {
      return;
    }
    snake_dir  = 1;
    break;

  case SDL_SCANCODE_S:
    if(snake_dir == 1) {
      return;
    }
    snake_dir  = 2;
    break;

  case SDL_SCANCODE_A:
    if(snake_dir == 4) {
      return;
    }
    snake_dir  = 3;
    break;

  case SDL_SCANCODE_D:
    if(snake_dir == 3) {
      return;
    }
    snake_dir  = 4;
    break;
  }
  glFlush();
  glFinish();
}
