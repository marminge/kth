#ifndef text_h_
#define text_h_

#include <SDL2/SDL_render.h>
typedef struct text Text;

Text *createText(int posX, int posY, SDL_Renderer *pRenderer);

void drawText(Text *pText);
void destroyText(Text *pText);

void updateText(Text *pText, int status, int height, float throttle,
                float velocity);

#endif
