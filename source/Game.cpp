#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include "../include/Game.h"
#include "../include/WindowRenderer.h"
#include "../include/GameObjects.h"
#include "../include/Camera.h"

Game::Game() : ptrWindow(nullptr), ptrCamera(nullptr), ptrGameObjects(nullptr), running(false)
{}

Game* Game::getInstance()
{
	if (pInstance == nullptr)
	{
		pInstance = new Game();

		return pInstance;
	}
	else
	{
		return pInstance;
	}
}

void Game::initialize(WindowRenderer* window, Camera* camera, GameObjects* gameObjects)
{
	ptrWindow = window;
	ptrCamera = camera;
	ptrGameObjects = gameObjects;
	running = false;
}

bool Game::handleInput(SDL_Event& e)
{
	if (e.type == SDL_QUIT) 
	{
		running = false;
	}
	else if (e.key.keysym.sym == SDLK_ESCAPE) 
	{
		// open menu
		running = false;
	}
	else if
		(
			e.key.keysym.sym == SDLK_a
			|| e.key.keysym.sym == SDLK_d
			|| e.key.keysym.sym == SDLK_s
			|| e.key.keysym.sym == SDLK_w
			|| e.key.keysym.sym == SDLK_SPACE
		)
	{
		ptrGameObjects->handleUserInput(e);
	}

	return true;
}

void Game::update(SDL_Event& e)
{
	while (SDL_PollEvent(&e) != 0)
	{
		handleInput(e);
	}

	ptrGameObjects->moveObjects();

	// update physics

	ptrGameObjects->checkCollisions(); // Once there are more collidables on the screen which have physics applied to them we will need a function like this.
}

bool Game::start()
{
	SDL_Event e;

	running = true;

	const int TICKS_PER_SECOND = 100;														// Desired speed of game.
	const float TIME_STEP = 1000.0 / TICKS_PER_SECOND;										// 10 ticks between updates.
	const int MAX_NUM_UPDATES = 10;															// max number of updates per render, 10 fps is minimum playable.

	Uint32 nextTick = SDL_GetTicks();														// count down times to next update.
	Uint16 numUpdates;
	float interpolation;																	// Come back to this.

	while (running)
	{	

		numUpdates = 0;
		while (nextTick < SDL_GetTicks() && numUpdates < MAX_NUM_UPDATES)
		{
			update(e);
		
			nextTick += TIME_STEP;
			numUpdates++;
		}

		// interpolation = float(SDL_GetTicks() + TIME_STEP - nextTick) / float(TIME_STEP);
		
		ptrGameObjects->moveCamera();
		ptrGameObjects->setOffsets();
		ptrGameObjects->clampCamera();

		ptrWindow->clearScreen();
		ptrGameObjects->renderObjects(/* interpolation */0);
		ptrWindow->display();
	}

	return true;
}

bool Game::stop()
{
	return false;
}