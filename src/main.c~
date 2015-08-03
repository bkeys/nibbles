#ifdef __MINGW32__
#include <windows.h>
#endif

#ifdef WIN32
#include <windows.h>
#endif

#include <GL/freeglut.h>
#include "board_helper.h"
#include "glut_func.h"

unsigned int board[9][9];

unsigned int row_selected  = 0;
unsigned int col_selected  = 0;

unsigned int screen_dim  = 300;

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
  write_board(".board1");
  glutInit(&argc, argv);
  glutCreateWindow("Sudoku");
  glutInitWindowSize(screen_dim, screen_dim);
  glutReshapeWindow(screen_dim, screen_dim);
  glutInitWindowPosition(50, 50);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  /*---------------------------------------------------------------------*/

  /*---- glut handling --------------------------------------------------*/
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutIdleFunc(idle);
  glutMouseFunc(mouse);
  glutMainLoop();
  /*---------------------------------------------------------------------*/

  return EXIT_SUCCESS;
}
