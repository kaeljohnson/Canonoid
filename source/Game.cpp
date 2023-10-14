#pragma once

#include "../include/Game.h"

Game::Game() : m_window(nullptr), m_gameObjects(nullptr), running(false)
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

void Game::initialize(WindowRenderer* window, GameObjects* gameObjects)
{
	m_window = window;
	m_gameObjects = gameObjects;
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
		m_gameObjects->handleUserInput(e);
	}

	return true;
}

void Game::update(SDL_Event& e)
{
	while (SDL_PollEvent(&e) != 0)
	{
		handleInput(e);
	}

	m_gameObjects->moveObjects();

	m_gameObjects->moveCamera();

	m_gameObjects->setOffsets();

	m_gameObjects->clampCamera();
}

void Game::renderGameObjects()
{
	// Need to only load part of the map in view.
	m_gameObjects->renderObjects();

	m_gameObjects->renderPlayer();
}

bool Game::start()
{
	SDL_Event e;
	//m_gameObjects.loadMap();

	running = true;

	while (running)
	{	
		update(e); // Update the physics of the simulation.

		// Note: the physics updates shuold be separate from the rendering updates.
	    	
		m_window->clearScreen();
		renderGameObjects();
		m_window->display();
	}

	return true;
}

bool Game::stop()
{
	return false;
}