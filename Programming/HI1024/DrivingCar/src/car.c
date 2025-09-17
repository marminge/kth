#include "../include/car.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <math.h>

typedef struct car {
  SDL_FRect carRect;
  SDL_Texture *pTexture;
  SDL_Renderer *pRenderer;
  double xSpeed, ySpeed;
  double angle;
} Car;

Car *createCar(SDL_Renderer *pRenderer, int height, int width, double xPos,
               double yPos, int angle) {
  Car *pCar = malloc(sizeof(struct car));
  SDL_Surface *pCarSurface = IMG_Load("resources/car.png");
  pCar->pRenderer = pRenderer;
  pCar->pTexture = SDL_CreateTextureFromSurface(pCar->pRenderer, pCarSurface);
  SDL_FreeSurface(pCarSurface);
  if (pCar->pTexture == NULL) {
    fprintf(stderr, "Error creating car texture: %s\n", SDL_GetError());
  }
  pCar->xSpeed = 0;
  pCar->ySpeed = 0;
  pCar->angle = angle;
  pCar->carRect.x = xPos;
  pCar->carRect.y = yPos;
  pCar->carRect.w = width;
  pCar->carRect.h = height;
  return pCar;
}

void calcSpeeds(Car *pCar) {
  pCar->xSpeed = -cos(pCar->angle * 2 * M_PI / 360);
  pCar->ySpeed = -sin(pCar->angle * 2 * M_PI / 360);
}

void accelerate(Car *pCar) {
  pCar->carRect.x += pCar->xSpeed;
  pCar->carRect.y += pCar->ySpeed;
}

void changeAngle(Car *pCar, double value) { pCar->angle += value; }

void destroyCar(Car *pCar) { SDL_DestroyTexture(pCar->pTexture); }
void drawCar(Car *pCar) {
  SDL_RenderCopyExF(pCar->pRenderer, pCar->pTexture, NULL, &(pCar->carRect),
                    pCar->angle, NULL, SDL_FLIP_NONE);
}
