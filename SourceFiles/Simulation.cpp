#include "Simulation.h"
#include "DrawingFunctions.h"

#include <cmath>
#include <string>

Simulation::Simulation() : WindowWidth(1280), WindowHeight(WindowWidth/16*9), FontSize(WindowWidth/40) {
	SDL_Init(SDL_INIT_VIDEO);
	Window = SDL_CreateWindow("Mandelbrot Fractal", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WindowWidth, WindowHeight, SDL_WINDOW_SHOWN);
	Surface = SDL_GetWindowSurface(Window);
	TTF_Init();
	Font = TTF_OpenFont("Font/Arial.ttf", FontSize);
	Quit = false;
	FractalTopLeft = { -2.0, -2.0 / WindowWidth * WindowHeight };
	FractalBottomRight = { 2.0, 2.0 / WindowWidth * WindowHeight };
	ZoomTopLeft = { 0.05, 0.05 };
	ZoomBottomRight = { 0.05, 0.05 };
	Iterations = 256;
	Pixels = new int[WindowWidth * WindowHeight] { 0 };
}

Simulation::~Simulation() {
	SDL_FreeSurface(TextSurface);
	SDL_FreeSurface(Surface);
	SDL_DestroyWindow(Window);
	TTF_Quit();
	SDL_Quit();
}

void Simulation::Traslation(int direction) {
	if (direction == 0) {
		FractalTopLeft.y += ZoomTopLeft.y;
		FractalBottomRight.y += ZoomBottomRight.y;
	}
	else if (direction == 1) {
		FractalTopLeft.y -= ZoomTopLeft.y;
		FractalBottomRight.y -= ZoomBottomRight.y;
	}
	else if (direction == 2) {
		FractalTopLeft.x -= ZoomTopLeft.x;
		FractalBottomRight.x -= ZoomBottomRight.x;
	}
	else if (direction == 3) {
		FractalTopLeft.x += ZoomTopLeft.x;
		FractalBottomRight.x += ZoomBottomRight.x;
	}
}


void Simulation::RenderText(std::string TextString, SDL_Surface *TextSurface, int x = 0, int y = 0) {
	TextSurface = TTF_RenderText_Solid(Font, TextString.c_str(), White);
	SDL_Rect TextRect = {x, y, 0, 0};
	SDL_BlitSurface(TextSurface, NULL, Surface, &TextRect);
}

void Simulation::Zoom(bool Zoom) {
	if (Zoom) {
		FractalTopLeft.x += ZoomTopLeft.x;
		FractalTopLeft.y += ZoomTopLeft.y / WindowWidth * WindowHeight;
		FractalBottomRight.x -= ZoomBottomRight.x;
		FractalBottomRight.y -= ZoomBottomRight.y / WindowWidth * WindowHeight;
	}
	else {
		FractalTopLeft.x -= ZoomTopLeft.x;
		FractalTopLeft.y -= ZoomTopLeft.y / WindowWidth * WindowHeight;
		FractalBottomRight.x += ZoomBottomRight.x;
		FractalBottomRight.y += ZoomBottomRight.y / WindowWidth * WindowHeight;
	}
}

void Simulation::GetCommands()
{
	while (SDL_PollEvent(&Event))
	{
		if (Event.type == SDL_QUIT || Event.key.keysym.sym == SDLK_ESCAPE)
		{
			Quit = true;
			break;
		}
		if (Event.type == SDL_MOUSEWHEEL)
		{
			if (Event.wheel.y > 0 && Iterations < 1024 << 4)
			{
				Iterations = Iterations << 1;
			}
			else if (Event.wheel.y < 0 && Iterations > 2)
			{
				Iterations = Iterations >> 1;
			}
		}
		

		if(Event.key.state == SDL_PRESSED)
		{
			if(Event.key.keysym.sym == SDLK_e)
			{
				Zoom(1);
			}
			if(Event.key.keysym.sym == SDLK_q)
			{
				Zoom(0);
			}
			if (Event.key.keysym.sym == SDLK_UP)
			{
				Traslation(1);
			}
			if (Event.key.keysym.sym == SDLK_DOWN)
			{
				Traslation(0);
			}
			if (Event.key.keysym.sym == SDLK_RIGHT)
			{
				Traslation(3);
			}
			if (Event.key.keysym.sym == SDLK_LEFT)
			{
				Traslation(2);
			}
		}
	}
}

//fare AVX2 e ThreadPool
void Simulation::Algorithm(){
	IterationStart = SDL_GetPerformanceCounter();
	Vec2<double> Position(FractalTopLeft.x, FractalTopLeft.y);
	int RowSize = WindowWidth;
	int x, y, n;
	double Cr = 0.0;
	double Ci = 0.0;
	double Zr = 0.0;
	double Zi = 0.0;
	double Re = 0.0;
	double Im = 0.0;
	for (y = 0; y < WindowHeight; y++) {
		Position.x = FractalTopLeft.x;
		Ci = Position.y;
		
		for (x = 0; x < WindowWidth; x++) {
			Cr = Position.x;
			Zr = 0.0;
			Zi = 0.0;
			n = 0;
			
			while ((Zr * Zr + Zi * Zi) < 2.0 * 2.0 && n < Iterations) {
				
				Re = Zr * Zr - Zi * Zi + Cr;
				Im = Zr * Zi * 2.0 + Ci;
				Zr = Re;
				Zi = Im;
				n++;
				
			}
			Pixels[y * WindowWidth + x] = n;
			Position.x += abs(FractalTopLeft.x - FractalBottomRight.x) / WindowWidth;
		}
		Position.y += abs(FractalTopLeft.y - FractalBottomRight.y) / WindowHeight;
	}
	IterationEnd = SDL_GetPerformanceCounter();
	ElapsedSeconds = (double)(IterationEnd - IterationStart) / (double)SDL_GetPerformanceFrequency();
}

void Simulation::Render() {
	double t;
	int n, r, g, b;
	for (int y = 0; y < WindowHeight; y++)
	{
		for (int x = 0; x < WindowWidth; x++)
		{
			n = Pixels[y * WindowWidth + x];
			t = (double)n / (double)Iterations;
			r = (int)(9.0 * (1 - t) * t * t * t * 255);
			g = (int)(15.0 * (1 - t) * (1 - t) * t * t * 255);
			b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
			DrawPixel(x, y, Surface, WindowWidth, r, g, b);
		}
	}
	std::string str = std::to_string(ElapsedSeconds);
	this->RenderText("DeltaTime: " + str, TextSurface);
	str = std::to_string(Iterations);
	this->RenderText("Iterations: " + str, TextSurface, 0, FontSize);
	SDL_UpdateWindowSurface(Window);
}

void Simulation::Cycle()
{
	while (!Quit)
	{
		this->GetCommands();
		if(Quit)
			break;
		this->Algorithm();
		this->Render();
	}
}