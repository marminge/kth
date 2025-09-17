#ifndef rocket_h_
#define rocket_h_

#include <SDL2/SDL_render.h>
typedef struct rocket Rocket;

Rocket *createRocket(int x, int y, SDL_Renderer *pRenderer);

void drawRocket(Rocket *pRocket);
void destroyRocket(Rocket *pRocket);
void accelerate(Rocket *pRocket, int throttle);
void updateRocket(Rocket *pRocket);
void reset(Rocket *pRocket);
int checkIfCrashed(Rocket *pRocket);

int getHeight(Rocket *pRocket);
float getVelocity(Rocket *pRocket);
float getThrottle(Rocket *pRocket);
#endif
