#include "TexHandler.hpp"
/*
SDL_Texture* TexHandler::GetTex(const char* s, SDL_Renderer* render)
{
	SDL_Surface* surf = IMG_Load(s);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(render, surf);
	SDL_FreeSurface(surf);
	return tex;
}

void TexHandler ::Draw(SDL_Texture* t, SDL_Rect srcR, SDL_Rect destR, SDL_Renderer* r)
{
	SDL_RenderCopy(r, t, &srcR, &destR);
}
*/
#include "TexHandler.hpp"
SDL_Texture* TexHandler::GetTex(const char* s, SDL_Renderer* renderer) {

    SDL_Surface* surf = IMG_Load(s);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_FreeSurface(surf);
    return tex;
}
void TexHandler::directDraw(SDL_Renderer* renderer, SDL_Texture* tex, SDL_Rect* src, SDL_Rect* dest) {

    SDL_RenderCopy(renderer, tex, src, dest);
}
