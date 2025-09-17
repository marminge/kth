#include "../include/car.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct game {
  SDL_Renderer *pRenderer;
  SDL_Texture *pTexture;
  Car *pCar;
} Game;

bool init(Game *pGame);
bool handleInput(Game *pGame);
void run(Game *pGame);
void gameCleanup(Game *pGame);

int main(int argc, char *argv[]) {
  Game game;
  if (!init(&game)) {
    gameCleanup(&game);
    return 1;
  }
  run(&game);
  gameCleanup(&game);
  return 0;
}

void run(Game *pGame) {
  bool continueLoop = true;
  while (continueLoop) {
    continueLoop = handleInput(pGame);
    SDL_Delay(16);
    calcSpeeds(pGame->pCar);
    SDL_RenderClear(pGame->pRenderer);
    SDL_RenderCopy(pGame->pRenderer, pGame->pTexture, NULL, NULL);
    drawCar(pGame->pCar);
    SDL_RenderPresent(pGame->pRenderer);
  }
}

bool init(Game *pGame) {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    fprintf(stderr, "Error initializing SDL: %s\n", SDL_GetError());
    return false;
  }
  if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) == 0) {
    fprintf(stderr, "Error initializing IMG: %s\n", SDL_GetError());
    return false;
  }
  SDL_Window *gameWindow =
      SDL_CreateWindow("Driving Car", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, 1000, 1000, SDL_WINDOW_OPENGL);
  pGame->pRenderer =
      SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_ACCELERATED);
  SDL_Surface *pBackgroundSurface = IMG_Load("resources/background.jpg");
  pGame->pTexture =
      SDL_CreateTextureFromSurface(pGame->pRenderer, pBackgroundSurface);
  SDL_FreeSurface(pBackgroundSurface);
  if (pGame->pTexture == NULL) {
    fprintf(stderr, "Error creating background texture: %s\n", SDL_GetError());
    return false;
  }
  pGame->pCar = createCar(pGame->pRenderer, 40, 70, 13.5, 194, 270);

  return true;
}

bool handleInput(Game *pGame) {
  SDL_Event e;
  const Uint8 *keystate;
  while (SDL_PollEvent(&e)) {
    switch (e.type) {
    case SDL_QUIT:
      return false;
      break;
    default:
      break;
    }
  }
  keystate = SDL_GetKeyboardState(NULL);
  if (keystate[SDL_SCANCODE_LEFT])
    changeAngle(pGame->pCar, -2);
  if (keystate[SDL_SCANCODE_RIGHT])
    changeAngle(pGame->pCar, 2);
  if (keystate[SDL_SCANCODE_SPACE])
    accelerate(pGame->pCar);
  return true;
}

void gameCleanup(Game *pGame) {
  destroyCar(pGame->pCar);
  SDL_DestroyRenderer(pGame->pRenderer);
  IMG_Quit();
  SDL_Quit();
}
