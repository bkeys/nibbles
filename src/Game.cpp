#include "Game.hpp"

/*F***********************************************************
 * DEFAULT CONSTRUCTOR
 *
 * PURPOSE : Initializes FreeGlut, OpenGL, and SDL2 to create
 *           a window with a 3D scene ready for rendering.
 *
 * NOTES :
 *F*/

Game::Game() {

  paused = false;
  char fakeParam[] = "fake";
  char *fakeargv[] = { fakeParam, NULL };
  int fakeargc = 1;
  glutInit(&fakeargc, fakeargv);
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_ShowCursor(SDL_DISABLE);
  SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_OPENGL, &displayWindow, &displayRenderer);
  SDL_GetRendererInfo(displayRenderer, &displayRendererInfo);
  if((displayRendererInfo.flags & SDL_RENDERER_ACCELERATED) == 0 ||
     (displayRendererInfo.flags & SDL_RENDERER_TARGETTEXTURE) == 0) {
    exit(1);
  }

  SDL_GL_LoadLibrary(nullptr);
  // Request an OpenGL 4.5 context (should be core)
  SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
  // Also request a depth buffer
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
  maincontext = SDL_GL_CreateContext(displayWindow);
  /*---- initialization ------------------------------------*/
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
  /*--------------------------------------------------------*/

  /*setting up viewport*/
  int width  = 800;
  int height = 600;

  /* Height / width ration */
  GLfloat ratio;

  /* Protect against a divide by zero */
  if (height == 0) {
    height = 1;
  }

  ratio = static_cast<GLfloat>(width) / static_cast<GLfloat>(height);

  glViewport(0, 0, static_cast<GLsizei>(width), static_cast<GLsizei>(height));

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluPerspective(45.0f, ratio, 0.1f, 100.0f);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(-9.5f, -5.0f, -19);


}

/*F***********************************************************
 * DESTRUCTOR
 *
 * NOTES :
 *F*/
Game::~Game() {

  SDL_DestroyRenderer(displayRenderer);
  SDL_DestroyWindow(displayWindow);
  SDL_Quit();
}
