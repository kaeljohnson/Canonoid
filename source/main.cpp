
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

#include "../include/WindowRenderer.h"
#include "../include/Levels.h"
#include "../include/Level.h"
#include "../include/Util.h"
#include "../include/Game.h"
#include "../include/Textures.h"

void initializeSDLFeatures() 
{
	if (!IMG_Init(IMG_INIT_PNG))
		printf("IMG Init failed! SDL_Error: %s\n", SDL_GetError());

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		printf("SDL Init failed! SDL_Error: %s\n", SDL_GetError());
}

WindowRenderer& initializeWindow() 
{
	WindowRenderer window("Canonoid v1", util::getScreenWidth(), util::getScreenHeight());
	return window;
}

void cleanUp(WindowRenderer& window) 
{
	window.free();
	SDL_Quit();
	IMG_Quit();
}

int main(int argc, char* args[])
{
	initializeSDLFeatures();
	
	WindowRenderer window = initializeWindow();
	Level playground(levels::getPlayground());

	Game newGame(window, playground);

	newGame.start();
	newGame.stop();
	
	cleanUp(window);

	return 0;
}