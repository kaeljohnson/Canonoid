#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <unordered_map>

#include "../include/WindowRenderer.h"
#include "../include/Levels.h"
#include "../include/Level.h"
#include "../include/Util.h"
#include "../include/Game.h"
#include "../include/Textures.h"
#include "../include/Camera.h"
#include "../include/PlayerConfig.h"

Game* Game::pInstance = nullptr;

void initializeSDLFeatures() 
{
	if (!IMG_Init(IMG_INIT_PNG))
		printf("IMG Init failed! SDL_Error: %s\n", SDL_GetError());

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		printf("SDL Init failed! SDL_Error: %s\n", SDL_GetError());
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

	WindowRenderer window("Adam v1", util::getScreenWidth(), util::getScreenHeight());

	SDL_Texture* floor1 = window.loadTexture(textureImages::getFloor1());

	std::unordered_map<std::string, SDL_Texture*> levelTextures = { {"floor1", floor1} };

	Level level(&window, levelTextures);
	PlayerConfig playerConfig(window.loadTexture(textureImages::getPlayerPng()),				// Player texture
							  level.getPlayerStartingX(),										// Starting x
							  level.getPlayerStartingY(),										// Starting y
							  8,																// Texture starting x
							  48,																// Texture ending x
							  0,																// Texture starting y
							  64,																// Texture ending y
							  4,																// Starting walk velocity
							  6,															    // Starting run velocity
							  2,																// Starting jump velocity
							  true);															// Physics on?

	Camera camera(0,																			// Camera starting x
				  0,																			// Camera starting y
				  util::getScreenWidth(),														// Camera width
				  util::getScreenHeight(),														// Camera height
				  level.getLevelDetails().m_levelWidthInPixels,									// Level width
				  level.getLevelDetails().m_levelHeightInPixels);								// Level height

	GameObjects gameObjects(window, playerConfig, camera, level);

	Game* newGame = Game::getInstance();
	
	newGame->initialize(&window, &camera, &gameObjects);
	newGame->start();
	newGame->stop();
	
	cleanUp(window);
	gameObjects.cleanUp();

	return 0;
}