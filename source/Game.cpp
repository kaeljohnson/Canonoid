#include "../include/Game.h"

Game::Game(WindowRenderer& window, GameObjects& gameObjects, Level& level)
	: m_window(window), m_level(level), m_gameObjects(gameObjects)
{

}

bool Game::handleUserInput(SDL_Event& e)
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

	return true;
}


void Game::update(SDL_Event& e, float deltaTime)
{
	while (SDL_PollEvent(&e) != 0)
	{
		handleUserInput(e);
	}

	//updatePhys();
	//updatePlayer();

}

void Game::renderGameObjects()
{
	m_window.render(*(m_gameObjects.getPlayer()));
}

bool Game::start()
{
	SDL_Event e;
	running = true;

	float latestTime = util::getAmountOfTimePassedFromStartInSeconds();
	float accumulator = 0.0f;
	float timeStep = util::getTimeDelta();

	while (running)
	{
		float newTime = util::getAmountOfTimePassedFromStartInSeconds();
		float frameTime = newTime - latestTime;

		latestTime = newTime;
		accumulator += frameTime;

		while (accumulator >= timeStep) 
		{
			
			update(e, timeStep);

			accumulator -= timeStep;
		}
		const float alpha = accumulator / timeStep;

	    	
		m_window.clearScreen();
		renderGameObjects();
		m_window.display();
	}

	return true;
}

bool Game::stop()
{
	return false;
}