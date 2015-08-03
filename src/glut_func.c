#include "glut_func.h"

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
  
  glClearColor (255, 255, 255, 1);
  glClear(GL_COLOR_BUFFER_BIT);

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
void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);

  glLoadIdentity();

  update_arena();
  
  glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
  // Compute aspect ratio of the new window
  if(height == 0) height = 1;                // To prevent divide by 0
  GLfloat aspect = (GLfloat)width / (GLfloat)height;

  // Set the viewport to cover the new window
  glViewport(0, 0, width, height);

  // Set the aspect ratio of the clipping volume to match the viewport
  glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
  glLoadIdentity();             // Reset
  // Enable perspective projection with fovy, aspect, zNear and zFar
  gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

/*F******************************************************************
 * keyboard(unsigned char key, int x, int y)
 * 
 * PURPOSE : our glutKeyboardFunc, it enables the user to control the
 *           snake and to exit the game
 *
 * RETURN :  void
 *
 * NOTES :   
 *F*/
void keyboard(unsigned char key, int x, int y) {

  switch(key) {

  case 'Q':
  case 'q':
    glutLeaveMainLoop();
    break;

  }
  glutPostRedisplay();

}
