#include "game.hpp"
#include "TexHandler.hpp"
#include "Element.hpp"
#include "movablemap.hpp"

//important variables
Element* playerTex;
movablemap* map1;

Game::Game()
{

}
Game::~Game()
{

}
void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flag = 0; //unless the bool is true then it is not fullscreen
	if (fullscreen)
	{
		flag = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flag);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}
		isRunning = true;
	}


	map1 = new movablemap("..\\Assets\\dungeon1.png", renderer, 0, 0);
	playerTex = new Element("..\\Assets\\hero.png", renderer, 0, 0, map1);

}
void Game::update()
{

	playerTex->Update("");
	map1->Update("");


	const Uint8* state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_UP]) {
		playerTex->Update("up");
		map1->Update("up");
	}
	else if (state[SDL_SCANCODE_DOWN]) {
		playerTex->Update("down");
		map1->Update("down");
	}
	else if (state[SDL_SCANCODE_RIGHT]) {
		playerTex->Update("right");
		map1->Update("right");
	}
	else if (state[SDL_SCANCODE_LEFT]) {
		playerTex->Update("left");
		map1->Update("left");
	}



}
void Game::handleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			isRunning = false;
		}

	}
	//    switch (event.type)
	//    {
	//        case SDL_QUIT:
	//        {isRunning = false;
	//            break;}
	//        default:
	//        {break;}
	//    }
	//    const Uint8* state = SDL_GetKeyboardState(NULL);
	//    if(state[SDL_SCANCODE_UP]){
	//        cout<<"up"<<endl;
	//    }
	//    else if (state[SDL_SCANCODE_DOWN]){
	//        cout<<"down"<<endl;
	//    }

}
void Game::render()
{
	//clear the renderer stuff from before
	SDL_RenderClear(renderer);
	//print the contents of the updated backbuffer once a frame
	map1->Render();
	playerTex->Render();
	SDL_RenderPresent(renderer);
}
void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}
bool Game::running()
{
	return isRunning;
}


/*
#ifndef xyy
#define xyy
 // !xyy

#include "game.hpp"
#include "TexHandler.hpp"
#include "Element.h"
#include "Map.h"
#include"KeyIn.cpp"

Element* playerTex;
Map* map;
KeyIn* playerKey;
SDL_Event Game::event;

Game::Game()
{

}
Game::~Game()
{

}
void Game::init(const char * title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flag = 0; //unless the bool is true then it is not fullscreen
	if (fullscreen)
	{
		flag = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		isRunning = true;
		cout << "All systems are go!" << endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flag);
		if (window)
		{
			cout << "Window has been created"
				<< endl;
		}
		else {
			isRunning = false;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			cout << "renderer running" << endl;
		}
		else {
			isRunning = false;
		}
	}
	else {
		isRunning = false;
	}
	//SDL_Surface* tempSurface = IMG_Load("..\\Textures\\idle.png");
	//C:\\Users\\Shreyansh\\Desktop\\Legend_of_jagger\\Free Assset - Adventurer Sword and Shield for itch.io\\Sprites\\indivuals\\idle.png
	playerTex = new Element("..\\Textures\\player.png", renderer, 0, 0,32,32);
	playerKey = new KeyIn(playerTex);
	//SDL_FreeSurface(tempSurface);
	map = new Map(renderer);
	
}
void Game::update()
{
	playerKey->update();
	playerTex->Update();
	//cout << playerTex->getX() << endl;
	
	map->Load();
}
void Game::handleEvents()
{
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;

	default:
		break;
	}
}
void Game::render()
{
	//clear the renderer stuff from before
	SDL_RenderClear(renderer);
	//print the contents of the updated backbuffer once a frame
	map->Draw();
	playerTex->Render();
	SDL_RenderPresent(renderer);
}
void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}
bool Game::running()
{
	return isRunning;
}


#endif

*/