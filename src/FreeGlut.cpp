#include "FreeGlut.h"

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
FreeGlut::FreeGlut() {

  char fakeParam[] = "fake";
  char *fakeargv[] = { fakeParam, NULL };
  int fakeargc = 1;

  glutInit( &fakeargc, fakeargv );
  glutCreateWindow("3D Snake");
  glutInitWindowSize(600, 300);
  glutReshapeWindow(600, 300);
  glutInitWindowPosition(50, 50);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClearDepth(1.0f);
  /*---------------------------------------------------------------------*/

  /*---- initialization -------------------------------------------------*/
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_COLOR_MATERIAL);
  glDepthFunc(GL_LEQUAL);
  glShadeModel(GL_SMOOTH);
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  glClearColor (0.0, 0.0, 0.0, 0.0);
  glShadeModel (GL_SMOOTH);

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_NORMALIZE);
  //moving the matrix back
  //  glRotatef(10.0, 1.0, 0.0, 0.0);
  glTranslatef(0, 0, -25);
  /*---------------------------------------------------------------------*/

  glutIdleFunc(idle);
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutReshapeFunc(reshape);
  glutSpecialFunc(special);
  glutTimerFunc(0, timer, 0);

}

/*F******************************************************************
 * DESTRUCTOR
 * 
 * NOTES :   
 *F*/
FreeGlut::~FreeGlut() {

}

/*F******************************************************************
 * idle(void)
 * 
 * PURPOSE : Our glutIdleFunc, checks for errors
 *
 * RETURN :  void
 *
 * NOTES :   
 *F*/
void FreeGlut::idle(void) {
  
  if(glGetError() != GL_NO_ERROR) {
    glutLeaveMainLoop();
  }

  return;
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
void FreeGlut::display() {

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    update_arena();
  glFlush();
  glFinish();
  glutSwapBuffers();
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
void FreeGlut::reshape(GLsizei width, GLsizei height) {

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
 * keyboard(unsigned char key, int x, int y)
 * 
 * PURPOSE : our glutKeyboardFunc, it enables the user to exit the game
 *
 * RETURN :  void
 *
 * NOTES :   
 *F*/
void FreeGlut::keyboard(unsigned char key, int x, int y) {

  switch(key) {

  case 'P':
  case 'p':
    //pause game
    break;

  case 'W':
  case 'w':
    if(snake_dir == 2) {
      return;
    }
    snake_dir  = 1;
    break;

  case 'S':
  case 's':
    if(snake_dir == 1) {
      return;
    }
    snake_dir  = 2;
    break;

  case 'A':
  case 'a':
    if(snake_dir == 4) {
      return;
    }
    snake_dir  = 3;
    break;

  case 'D':
  case 'd':
    if(snake_dir == 3) {
      return;
    }
    snake_dir  = 4;
    break;

  case 'Q':
  case 'q':
    glutLeaveMainLoop();
    break;
  }
  glFlush();
  glFinish();
  glutPostRedisplay();
}

/*F******************************************************************
 * special(int key, int x, int y)
 * 
 * PURPOSE : our glutSpecialFunc, it enables the user to control the
 *           snake
 *
 * RETURN :  void
 *
 * NOTES :   
 *F*/
void FreeGlut::special(int key, int x, int y) {

  switch (key) {

  case GLUT_KEY_UP:
    if(snake_dir == 2) {
      return;
    }
    snake_dir  = 1;
    break;
  case GLUT_KEY_DOWN:
    if(snake_dir == 1) {
      return;
    }
    snake_dir  = 2;
    break;
  case GLUT_KEY_LEFT:
    if(snake_dir == 4) {
      return;
    }
    snake_dir  = 3;
    break;
  case GLUT_KEY_RIGHT:
    if(snake_dir == 3) {
      return;
    }
    snake_dir  = 4;
    break;
  }
  glutPostRedisplay();
}

/*F******************************************************************
 * timer(int value)
 * 
 * PURPOSE : To regulate the frame rate
 *
 * RETURN :  void
 *
 * NOTES :   
 *F*/
void FreeGlut::timer(int value) {
  
  const int desired_fps  = 20;
  static GLint frames = 0;         // frames averaged over 1000mS
  static GLuint clock;             // [milliSeconds]
  static GLuint next_clock = 0;     // [milliSeconds]

  glutTimerFunc(1000/desired_fps, timer, ++value);
  
  ++frames;
  clock = glutGet(GLUT_ELAPSED_TIME); //has limited resolution, so average over 1000mS
  if(clock < next_clock ) {
    glutPostRedisplay();
    return;
  }

  next_clock  = clock+1000; // 1000mS=1S in the future
  frames  = 0;

  glFlush();
  glFinish();
  glutPostRedisplay();
}
