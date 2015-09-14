#ifdef __MINGW32__
#include <windows.h>
#endif

#ifdef WIN32
#include <windows.h>
#endif

#include <GL/freeglut.h>
#include <time.h>
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

  srand(time(NULL));

  /*---- initialization -------------------------------------------------*/
  glutInit(&argc, argv);
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

  /*---- glut handling --------------------------------------------------*/
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutIdleFunc(idle);
  glutReshapeFunc(reshape);
  glutSpecialFunc(special);
  glutTimerFunc(0,timer,0);
  glutMainLoop();
  /*---------------------------------------------------------------------*/

  return EXIT_SUCCESS;
}
