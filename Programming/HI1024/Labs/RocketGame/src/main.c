#include "../include/rocket.h"
#include "../include/text.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_video.h>
#include <stdbool.h>

typedef struct game {
  SDL_Renderer *pRenderer;
  SDL_Window *pWindow;
  SDL_Texture *pBackgroundTexture;
  Rocket *pRocket;
  Text *pText;
} Game;

bool initialize(Game *pGame);
void drawBackground(Game *pGame);
void gameCleanup(Game *pGame);
void runGame(Game *pGame);
void updateBackground(Game *pGame);

int main(int argc, char *argv[]) {
  Game game = {0};

  initialize(&game);
  runGame(&game);
  gameCleanup(&game);
  return 0;
}

bool initialize(Game *pGame) {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    fprintf(stderr, "Error initializing SDL: %s\n", SDL_GetError());
    return true;
  }

  if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) == 0) {
    fprintf(stderr, "Error initializing IMG: %s\n", SDL_GetError());
    return true;
  }

  if (TTF_Init() == -1) {
    fprintf(stderr, "Error initializing TTF: %s\n", SDL_GetError());
    return true;
  }

  pGame->pWindow =
      SDL_CreateWindow("Rocket Game", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_OPENGL);
  if (pGame->pWindow == NULL) {
    fprintf(stderr, "Error initializing Window: %s\n", SDL_GetError());
    return true;
  }

  pGame->pRenderer =
      SDL_CreateRenderer(pGame->pWindow, -1, SDL_RENDERER_ACCELERATED);
  if (pGame->pRenderer == NULL) {
    fprintf(stderr, "Error initializing Renderer: %s\n", SDL_GetError());
    return true;
  }

  SDL_Surface *gameBackground = IMG_Load("resources/moon.jpeg");
  if (!gameBackground) {
    fprintf(stderr, "Error initializing Renderer: %s\n", SDL_GetError());
    return true;
  }
  pGame->pBackgroundTexture =
      SDL_CreateTextureFromSurface(pGame->pRenderer, gameBackground);
  SDL_FreeSurface(gameBackground);

  pGame->pRocket = createRocket(540, 200, pGame->pRenderer);
  pGame->pText = createText(20, 20, pGame->pRenderer);
  if (!pGame->pRocket || !pGame->pText) {
    fprintf(stderr, "Error creating %s\n", SDL_GetError());
    return true;
  }
  return false;
}

void runGame(Game *pGame) {
  int run = 1;
  SDL_Event e;
  while (run) {
    while (SDL_PollEvent(&e)) {
      switch (e.type) {
      case SDL_QUIT:
        run = 0;
        break;
      case SDL_KEYDOWN:
        switch (e.key.keysym.scancode) {
        case SDL_SCANCODE_UP:
          accelerate(pGame->pRocket, 8);
          break;
        case SDL_SCANCODE_SPACE:
          reset(pGame->pRocket);
          break;
        default:
          break;
        }
      }
    }
    int status = checkIfCrashed(pGame->pRocket);
    updateText(pGame->pText, status, getHeight(pGame->pRocket),
               getThrottle(pGame->pRocket), getVelocity(pGame->pRocket));

    SDL_Delay(50);
    SDL_RenderClear(pGame->pRenderer);
    drawBackground(pGame);

    drawText(pGame->pText);

    updateRocket(pGame->pRocket);
    drawRocket(pGame->pRocket);

    SDL_RenderPresent(pGame->pRenderer);

    if (status != 1) {
      SDL_Delay(5000);
      run = 0;
    }
  }
  gameCleanup(pGame);
}

void drawBackground(Game *pGame) {
  SDL_RenderCopy(pGame->pRenderer, pGame->pBackgroundTexture, NULL, NULL);
}

void gameCleanup(Game *pGame) {
  SDL_DestroyTexture(pGame->pBackgroundTexture);
  destroyRocket(pGame->pRocket);
  destroyText(pGame->pText);
  SDL_DestroyWindow(pGame->pWindow);
  SDL_DestroyRenderer(pGame->pRenderer);
  TTF_Quit();
  IMG_Quit();
  SDL_Quit();
}
