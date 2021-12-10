#pragma once
#include"game.hpp"
#include "SDL.h"
#include "SDL_image.h"

class Map
{
public :
	Map(SDL_Renderer * r);
	~Map();
	void Load();
	void Draw();
	static int maplv1[20][30];
	int map[20][30];
private :
	SDL_Rect srcR, destR;
	SDL_Texture* soil;
	SDL_Texture* water;
	SDL_Texture* grass;
	SDL_Renderer* renderer;
	
};