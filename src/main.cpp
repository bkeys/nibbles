#ifdef __MINGW32__
#include <windows.h>
#endif

#ifdef WIN32
#include <windows.h>
#endif

#include <stdio.h>
#include <GL/freeglut.h>
#include <SDL2/SDL.h>
#include <time.h>
#include "SnakeGame.h"

SDL_Renderer* displayRenderer;

/* function to reset our viewport after a window resize */
int Display_SetViewport() {

  return 1;
}

/*F******************************************************************
 * main(int argc, char **argv)
 * 
 * PURPOSE : entry into the program
 *
 * RETURN :  int
 *
 * NOTES :   Best viewed with emacs
 *F*/
int main(int argc, char *argv[]) {

  srand(time(NULL));

  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_Window* displayWindow;
  SDL_RendererInfo displayRendererInfo;
  SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_OPENGL, &displayWindow, &displayRenderer);
  SDL_GetRendererInfo(displayRenderer, &displayRendererInfo);
  SnakeGame f;
  bool is = true;
  SDL_Event event;
  Uint32 start;
  const int FPS = 20;

  if((displayRendererInfo.flags & SDL_RENDERER_ACCELERATED) == 0 ||
     (displayRendererInfo.flags & SDL_RENDERER_TARGETTEXTURE) == 0) {
    return 1;
  }

  Display_SetViewport();

  glTranslatef(-9.5f, -5.0f, -20.0f);
  while(is) {
    start = SDL_GetTicks();
    if(glGetError() != GL_NO_ERROR) {
      return 1;
    }

    while(SDL_PollEvent(&event) != 0) {

      switch(event.type){

      case SDL_KEYDOWN:
	f.keyboard(event);
	break;
      case SDL_QUIT:
	is = false;
	break;

      }
    }

    f.display();
    SDL_RenderPresent(displayRenderer);
    if(1000/FPS > SDL_GetTicks() - start) {
      SDL_Delay(1000/FPS - (SDL_GetTicks() - start));
    }
  }

  return 0;
}
