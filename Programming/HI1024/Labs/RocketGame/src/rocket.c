#include "../include/rocket.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>

typedef struct rocket {
  int x, y;
  float velocity, throttle;
  SDL_Texture *pTexture;
  SDL_Surface *pSurface;
  SDL_Renderer *pRenderer;
  SDL_Rect rocketRect;
} Rocket;

Rocket *createRocket(int x, int y, SDL_Renderer *pRenderer) {
  Rocket *pRocket = malloc(sizeof(struct rocket));
  pRocket->x = x;
  pRocket->y = y;
  pRocket->pRenderer = pRenderer;
  pRocket->pSurface = IMG_Load("resources/rocket.png");
  if (pRocket->pSurface == NULL) {
    fprintf(stderr, "Error loading rocket surface: %s\n", SDL_GetError());
  }
  pRocket->pTexture =
      SDL_CreateTextureFromSurface(pRocket->pRenderer, pRocket->pSurface);
  if (pRocket->pTexture == NULL) {
    fprintf(stderr, "Error creating rocket texture: %s\n", SDL_GetError());
  }

  pRocket->rocketRect.w = 72;
  pRocket->rocketRect.h = 116;
  pRocket->rocketRect.x = pRocket->x;
  pRocket->rocketRect.y = pRocket->y;
  pRocket->velocity = 0;
  pRocket->throttle = 0;
  return pRocket;
}

void drawRocket(Rocket *pRocket) {
  SDL_RenderCopy(pRocket->pRenderer, pRocket->pTexture, NULL,
                 &(pRocket->rocketRect));
}

void accelerate(Rocket *pRocket, int throttle) {
  pRocket->throttle += throttle;
}

void updateRocket(Rocket *pRocket) {
  pRocket->rocketRect.y = pRocket->rocketRect.y + pRocket->velocity +
                          (-0.5 * pRocket->throttle - 1.3) / 2;
  pRocket->velocity = pRocket->velocity + (-0.1 * pRocket->throttle + 1.2);

  pRocket->throttle *= 0.8;
}
void destroyRocket(Rocket *pRocket) { SDL_DestroyTexture(pRocket->pTexture); }

int getHeight(Rocket *pRocket) { return pRocket->rocketRect.y; }
float getVelocity(Rocket *pRocket) { return pRocket->velocity; }
float getThrottle(Rocket *pRocket) { return pRocket->throttle; }

void reset(Rocket *pRocket) {
  pRocket->rocketRect.y = 200;
  pRocket->throttle = 0;
  pRocket->velocity = 0;
}

int checkIfCrashed(Rocket *pRocket) {
  if (pRocket->rocketRect.y + 96 >= 720) {
    if (pRocket->velocity <= 10) {
      return 2;
    } else {
      return 3;
    }
  } else {
    return 1;
  }
}
