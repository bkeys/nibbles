#include "glut_func.h"
#include <stdio.h>

/*F******************************************************************
 * idle(void)
 * 
 * PURPOSE : Our glutIdleFunc, it updates the screen and it clears
 *           the screen and checks for any errors OpenGL might have. 
 *
 * RETURN :  void
 *
 * NOTES :   
 *F*/
void idle(void) {
  
  if(glGetError() != GL_NO_ERROR) {
    glutLeaveMainLoop();
  }

  glFlush();
  glFinish();
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
void display() {

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);

  glLoadIdentity();

  update_arena();
  
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
void reshape(GLsizei width, GLsizei height) {

  if(height == 0) height = 1;
  GLfloat aspect = (GLfloat)width / (GLfloat)height;

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
void keyboard(unsigned char key, int x, int y) {

  switch(key) {

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
void special(int key, int x, int y) {

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
void timer(int value) {
  
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
