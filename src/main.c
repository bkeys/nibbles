#ifdef __MINGW32__
#include <windows.h>
#endif

#ifdef WIN32
#include <windows.h>
#endif

#include <GL/freeglut.h>
#include "glut_func.h"

/*F******************************************************************
 * main(int argc, char **argv)
 * 
 * PURPOSE : entry into the program
 *
 * RETURN :  int
 *
 * NOTES :   Best viewed with emacs
 *F*/
int main(int argc, char **argv) {

  /*---- initialization -------------------------------------------------*/
  glutInit(&argc, argv);
  glutCreateWindow("3D Snake");
  glutInitWindowSize(600, 300);
  glutReshapeWindow(600, 300);
  glutInitWindowPosition(50, 50);
  glutInitDisplayMode(GLUT_DOUBLE);
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClearDepth(1.0f);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
  glShadeModel(GL_SMOOTH);
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
  /*---------------------------------------------------------------------*/

  /*---- glut handling --------------------------------------------------*/
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutIdleFunc(idle);
  glutReshapeFunc(reshape);
  glutMainLoop();
  /*---------------------------------------------------------------------*/

  return EXIT_SUCCESS;
}
