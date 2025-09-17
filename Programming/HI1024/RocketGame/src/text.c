#include "../include/text.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_ttf.h>
#include <stddef.h>

typedef struct text {
  int posX, posY;
  TTF_Font *pFont;
  SDL_Color color;
  SDL_Surface *pSurface;
  SDL_Texture *pTexture;
  SDL_Renderer *pRenderer;
  SDL_Rect pRect;
  char texten[150];
} Text;

Text *createText(int posX, int posY, SDL_Renderer *pRenderer) {
  Text *pText = malloc(sizeof(struct text));
  SDL_Color white = {230, 230, 230};
  pText->pRenderer = pRenderer;
  pText->color = white;
  pText->pFont = TTF_OpenFont("Montserrat-Regular.ttf", 32);
  if (pText->pFont == 0) {
    fprintf(stderr, "Error opening font: %s\n", SDL_GetError());
  }

  pText->pRect.x = 20;
  pText->pRect.y = 20;
  return pText;
}

void updateText(Text *pText, int status, int height, float throttle,
                float velocity) {
  switch (status) {
  case 1:
    sprintf(pText->texten, "Height: %d Throttle: %.1f Velocity: %.1f",
            -(height - 720), throttle, velocity);
    break;
  case 2:
    sprintf(pText->texten, "You successfully landed with a velocity of %.1f",
            velocity);
    break;
  case 3:
    sprintf(pText->texten, "You crashed with a velocity of %.1f", velocity);
    break;
  default:
    break;
  }
  pText->pSurface =
      TTF_RenderText_Blended(pText->pFont, pText->texten, pText->color);
  pText->pTexture =
      SDL_CreateTextureFromSurface(pText->pRenderer, pText->pSurface);
  pText->pRect.h = pText->pSurface->h;
  pText->pRect.w = pText->pSurface->w;
  SDL_FreeSurface(pText->pSurface);
}

void drawText(Text *pText) {
  SDL_RenderCopy(pText->pRenderer, pText->pTexture, NULL, &(pText->pRect));
}

void destroyText(Text *pText) { SDL_DestroyTexture(pText->pTexture); }
