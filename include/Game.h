#pragma once

#include "Player.h"
#include "WindowRenderer.h"
#include "Level.h"
#include "Util.h"
#include "Player.h"
#include "Tile.h"
#include "Textures.h"

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>


class Game 
{
private:

	bool running = false;

	WindowRenderer& m_window;
	Level& m_level;

public:
	Game(WindowRenderer& window, Level& level);

	bool handleUserInput(SDL_Event& e);
	void update(SDL_Event& e, float timeStep);

	bool start();
	bool stop();
};