#include "SnakeGame.hpp"

SnakeGame::SnakeGame() :
Game() {
  is = true;
}

SnakeGame::~SnakeGame() {}

void SnakeGame::run(void) {
  SDL_Event event;
  Uint32 start;
  const int FPS = 20;

  while(is) {
    start = SDL_GetTicks();
    if(glGetError() != GL_NO_ERROR) {
      std::cout << "OpenGL Error!" << std::endl;
      exit(1);
    }

    while(SDL_PollEvent(&event) != 0) {

      switch(event.type){

      case SDL_KEYDOWN:
	keyboard(event);
	break;
      case SDL_QUIT:
	is = false;
	break;
      default:
	break;
      }
    }

    if(!paused) {
      arena.update();
    }
        SDL_GL_SwapWindow(displayWindow);

    //SDL_RenderPresent(displayRenderer);
    if(1000/FPS > SDL_GetTicks() - start) {
      SDL_Delay(1000/FPS - (SDL_GetTicks() - start));
    }
  }
}

void SnakeGame::keyboard(const SDL_Event &event) {

  switch(event.key.keysym.scancode) {

  case SDL_SCANCODE_P:
    if(!paused) {
      paused = true;
    } else {
      paused = false;
    }
    return;

  case SDL_SCANCODE_Q:
    is = false;
    return;

  case SDL_SCANCODE_W:
    arena.snake->setDir(UP);
    return;

  case SDL_SCANCODE_S:
    arena.snake->setDir(DOWN);
    return;

  case SDL_SCANCODE_A:
    arena.snake->setDir(LEFT);
    return;

  case SDL_SCANCODE_D:
    arena.snake->setDir(RIGHT);
    return;
  default:
    break;

  }
  //glFlush();
  //glFinish();
}
