#include "../include/Game.h"
#include "../include/Entity.h"

Game::Game(WindowRenderer& window, GameObjects& gameObjects)
	: m_window(window), m_gameObjects(gameObjects)
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
		// handle other player related input.
	}

	return true;
}


void Game::update(SDL_Event& e, double time, double deltaTime)
{
	while (SDL_PollEvent(&e) != 0)
	{
		handleUserInput(e);
	}

	// TO-DO: how to apply physics to the player and the AI enemies?
	// I.E. When the player gets hit.

	//updatePhys(); // Apply the physics to all game object states.
	
	//updatePlayer();
	m_gameObjects.getPlayer()->move(deltaTime);
}

void Game::renderGameObjects()
{
	m_window.render(*(m_gameObjects.getPlayer()));

	// Need to only load part of the map in view.
	m_gameObjects.loadMap();
}

bool Game::start()
{
	SDL_Event e;
	// loadGameStates(); // Each entity has-a state 
	//m_gameObjects.loadMap();

	running = true;

	double latestTime = util::getAmountOfTimePassedFromStartInSeconds();
	double timeStep = util::getTimeDelta();
	double timeElapsed = 0.0f;
	//double accumulator = 0.0f;

	while (running)
	{
		double newTime = util::getAmountOfTimePassedFromStartInSeconds();
		double frameTime = newTime - latestTime;

		latestTime = newTime;
		//accumulator += frameTime;

		//while (accumulator >= timeStep) 
		//{
			// we can view all the object states in the gameObjects class, and have a container where we can store the previous states in
			// so we can make this interpolation work.
			// previousState = currentState;
			// integrate(currentState, t, dt);
			// t += dt;
			// accumulator -= dt;

		    // May want to pass frame time to handle any lags in the physics simulation.
			update(e, timeElapsed, timeStep); // Update the physics of the simulation.

			timeElapsed += timeStep;
			//accumulator -= timeStep;
		//}
		//const double alpha = accumulator / timeStep;

		//m_gameObjects.updateGameObjectStates(alpha, prevXForPlayer, prevYForPlayer); // Interpolate extra time in the accumulator for smooth rendering.
		// Equation for interpolation: currentState * alpha + previousState* (1.0 - alpha);

		// FYI: By current/previous state, it means all the current/previous states for all the objects positions for the time being. May need to adjust this definition
		// when the physics get morde advanced.
       

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