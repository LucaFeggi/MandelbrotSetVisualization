#include "DrawingFunctions.h"

#include <cmath>

void DrawPixel(int x, int y, SDL_Surface *MySurface, int WindowWidth, SDL_Color Color){
	uint8_t* PixelPtr = (uint8_t*)MySurface->pixels + (y * WindowWidth + x) * 4;
	*(PixelPtr + 2) = Color.r;
	*(PixelPtr + 1) = Color.g;
	*(PixelPtr) = Color.b;
}

void DrawPixel(int x, int y, SDL_Surface *MySurface, int WindowWidth, int r, int g, int b){
	uint8_t* PixelPtr = (uint8_t*)MySurface->pixels + (y * WindowWidth + x) * 4;
	*(PixelPtr + 2) = r;
	*(PixelPtr + 1) = g;
	*(PixelPtr) = b;
}

