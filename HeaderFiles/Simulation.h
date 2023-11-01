#pragma once

#include "Vec2.h"

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

class Simulation{
	public:
		Simulation();
		~Simulation();
		void RenderText(std::string TextString, SDL_Surface *TextSurface, int x, int y);
		void GetCommands();
		void Zoom(bool Zoom);
		void Algorithm();
		void Render();
		void Cycle();
	private:
		const int WindowWidth, WindowHeight;
		const int FontSize;
		SDL_Window *Window = nullptr;
		SDL_Surface *Surface = nullptr;
		TTF_Font *Font = nullptr;
		SDL_Surface *TextSurface = nullptr;
		Uint64 IterationStart, IterationEnd;
		double ElapsedSeconds;
		SDL_Event Event;
		bool Quit;

		Vec2<double> FractalTopLeft;
		Vec2<double> FractalBottomRight;
		Vec2<double> ZoomTopLeft;
		Vec2<double> ZoomBottomRight;
		int Iterations;
		int* Pixels = nullptr;
};
