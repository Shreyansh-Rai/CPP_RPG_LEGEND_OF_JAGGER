#include <iostream>
#include<stdio.h>
#include "SDL.h"
#include "game.hpp"
using namespace std;
Game* game = NULL;
int main(int argc, char* argv[])
{
	/*
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("LOJ", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	SDL_Delay(3000);
	*/
	game = new Game();
	const int FPS = 60;
	const int delay = 1000 / FPS; //time per frame
	unsigned int st;
	unsigned int timeperframe;
	game->init("LOJ", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, false);
	while (game->running())
	{
		st = SDL_GetTicks();
		game->handleEvents();
		game->update();
		game->render();
		timeperframe = SDL_GetTicks() - st;
		if (timeperframe < delay)
		{
			SDL_Delay(delay - timeperframe);
		}
	}
	game->clean();
	return 0;
}
