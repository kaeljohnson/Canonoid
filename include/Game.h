#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

#include "Player.h"
#include "WindowRenderer.h"
#include "Level.h"
#include "Util.h"
#include "Player.h"
#include "Tile.h"
#include "Textures.h"
#include "GameObjects.h"

class Game 
{
private:

	bool running = false;

	WindowRenderer& m_window;
	GameObjects& m_gameObjects;
	Level& m_level;

public:
	Game(WindowRenderer& window, GameObjects& gameObjects, Level& level);

	bool handleUserInput(SDL_Event& e);
	void update(SDL_Event& e, double time, double timeStep);
	void renderGameObjects();

	bool start();
	bool stop();
};