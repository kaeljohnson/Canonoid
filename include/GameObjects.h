#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

#include "Player.h"
#include "WindowRenderer.h"
#include "Textures.h"
#include "Tile.h"

class GameObjects
{
private:
	Player* m_player;
	SDL_Texture* m_floorSprite;
	Level& m_level;
	WindowRenderer& m_window;

public:
	GameObjects(WindowRenderer& window, Level& level);
	Player* getPlayer();
	void updateGameObjectStates(double alpha, double prevX, double prevY);

	bool loadMap();
};