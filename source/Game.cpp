#include "../include/Game.h"
#include "../include/Entity.h"

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
	else if
		(
			e.key.keysym.sym == SDLK_a
			|| e.key.keysym.sym == SDLK_d
			|| e.key.keysym.sym == SDLK_s
			|| e.key.keysym.sym == SDLK_w
			|| e.key.keysym.sym == SDLK_SPACE
		)
	{
		m_gameObjects.getPlayer()->handleMoveInput(e);
	}

	return true;
}


void Game::update(SDL_Event& e, double time, double deltaTime)
{
	while (SDL_PollEvent(&e) != 0)
	{
		handleUserInput(e);
	}

	//updatePhys(); // Apply the physics to all game object states.
	//updatePlayer();
	m_gameObjects.getPlayer()->move(deltaTime);

}

void Game::renderGameObjects()
{
	m_window.render(*(m_gameObjects.getPlayer()));
}

bool Game::start()
{
	SDL_Event e;
	// loadGameStates(); // Each entity has-a state 
	// loadMap();

	running = true;

	double latestTime = util::getAmountOfTimePassedFromStartInSeconds();
	double timeStep = util::getTimeDelta();
	double timeElapsed = 0.0f;
	double accumulator = 0.0f;

	while (running)
	{
		double newTime = util::getAmountOfTimePassedFromStartInSeconds();
		double frameTime = newTime - latestTime;

		latestTime = newTime;
		accumulator += frameTime;

		while (accumulator >= timeStep) 
		{
			
			// previousState = currentState;
			// integrate(currentState, t, dt);
			// t += dt;
			// accumulator -= dt;

			update(e, timeElapsed, timeStep); // Update the physics of the simulation.

			timeElapsed += timeStep;
			accumulator -= timeStep;
		}
		const double alpha = accumulator / timeStep;

		m_gameObjects.updateGameObjectStates(); // Interpolate extra time in the accumulator for smooth rendering.

		// Note: the physics updates are separate from the rendering updates.
	    	
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