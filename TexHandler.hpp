

/*
class TexHandler
{
public :
	static SDL_Texture* GetTex(const char* s, SDL_Renderer* render);
	static void Draw(SDL_Texture* t, SDL_Rect srcR, SDL_Rect destR, SDL_Renderer* r);
private:

};*/

#include <iostream>

#ifndef TexHandler_hpp
#define TexHandler_hpp
#include "SDL.h"
#include "SDL_image.h"
#include "game.hpp"
#include <stdio.h>

class TexHandler {
public:
    static SDL_Texture* GetTex(const char* s, SDL_Renderer* renderer);
    static void directDraw(SDL_Renderer* renderer, SDL_Texture* tex, SDL_Rect* src, SDL_Rect* dest);
private:
};

#endif /* TexHandler_hpp */
