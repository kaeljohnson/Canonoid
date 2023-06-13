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

		// refactor these doubles into state objects?
		double prevXForPlayer = m_gameObjects.getPlayer()->state.getXPos();
		double prevYForPlayer = m_gameObjects.getPlayer()->state.getYPos();

		//while (accumulator >= timeStep) 
		//{
			// we can view all the object states in the gameObjects class, and have a container where we can store the previous states in
			// so we can make this interpolation work.
			// previousState = currentState;
			// prevXForPlayer = m_gameObjects.getPlayer()->state.getXPos();
			// prevYForPlayer = m_gameObjects.getPlayer()->state.getYPos();
			// integrate(currentState, t, dt);
			// t += dt;
			// accumulator -= dt;

			update(e, timeElapsed, timeStep); // Update the physics of the simulation.

			timeElapsed += timeStep;
			accumulator -= timeStep;
		//}
		const double alpha = accumulator / timeStep;

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