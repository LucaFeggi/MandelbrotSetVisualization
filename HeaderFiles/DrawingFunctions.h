#pragma once

#include <SDL.h>

const SDL_Color White = {0xff, 0xff, 0xff};
const SDL_Color Black = {0x00, 0x00, 0x00};

void DrawPixel(int x, int y, SDL_Surface *MySurface, int WindowWidth, SDL_Color Color);
void DrawPixel(int x, int y, SDL_Surface *MySurface, int WindowWidth, int r, int g, int b);
