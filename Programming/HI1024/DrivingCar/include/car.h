#ifndef car_h_
#define car_h_
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

typedef struct car Car;
Car *createCar(SDL_Renderer *pRenderer, int height, int width, double xPos,
               double yPos, int angle);
void calcSpeeds(Car *pCar);
void accelerate(Car *pCar);
void changeAngle(Car *pCar, double value);
void destroyCar(Car *pCar);
void drawCar(Car *pCar);
#endif
