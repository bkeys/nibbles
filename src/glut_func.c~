#include "glut_func.h"

/*F******************************************************************
 * idle(void)
 * 
 * PURPOSE : Our glutIdleFunc, it simply clears the screen and checks
 *           for any errors OpenGL might have. 
 *
 * RETURN :  void
 *
 * NOTES :   
 *F*/
void idle(void) {
  
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f );
  glClear(GL_COLOR_BUFFER_BIT);

  if(glGetError() != GL_NO_ERROR) {
    glutLeaveMainLoop();
  }

  return;
}

/*F******************************************************************
 * display(void)
 * 
 * PURPOSE : Our glutDisplayFunc, it draws the borders of the board
 *           and it draws the values inside of the board to the screen
 *
 * RETURN :  void
 *
 * NOTES :   
 *F*/
void display(void) {

  draw_board();
  draw_numbers();
  
  glutPostRedisplay();
  return;
}

/*F******************************************************************
 * keyboard(unsigned char key, int x, int y)
 * 
 * PURPOSE : our glutKeyboardFun, it handles user input into squares
 *           and when the user exits the game
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

  case '1':
    if(check_value(row_selected, col_selected, 1)) { 
      board[col_selected][row_selected]  = 1;
    }
    return;

  case '2':
    if(check_value(row_selected, col_selected, 2)) { 
      board[col_selected][row_selected]  = 2;
    }
    return;

  case '3':
    if(check_value(row_selected, col_selected, 3)) { 
      board[col_selected][row_selected]  = 3;
    }
    return;
      
  case '4':
    if(check_value(row_selected, col_selected, 4)) { 
      board[col_selected][row_selected]  = 4;
    }
    return;
      
  case '5':
    if(check_value(row_selected, col_selected, 5)) { 
      board[col_selected][row_selected]  = 5;
    }
    return;
      
  case '6':
    if(check_value(row_selected, col_selected, 6)) { 
      board[col_selected][row_selected]  = 6;
    }
    return;
      
  case '7':
    if(check_value(row_selected, col_selected, 7)) { 
      board[col_selected][row_selected]  = 7;
    }
    return;
      
  case '8':
    if(check_value(row_selected, col_selected, 8)) { 
      board[col_selected][row_selected]  = 8;
    }
    return;
      
  case '9':
    if(check_value(row_selected, col_selected, 9)) { 
      board[col_selected][row_selected]  = 9;
    }
    return;

  case '0':
    board[col_selected][row_selected]  = 0;
    return;
  }
  glutPostRedisplay();

}

/*F******************************************************************
 * mouse(int button, int state, int x, int y) {
 * 
 * PURPOSE : Our glutMouseFunc, sets the value that the user currently
 *           has selected
 *
 * RETURN :  void
 *
 * NOTES :   
 *F*/
void mouse(int button, int state, int x, int y) {

  row_selected  = x / (screen_dim / 9);
  col_selected  = y / (screen_dim / 9);
}
