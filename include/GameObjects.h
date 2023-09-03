#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <vector>

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
	// std::unordered_map<bool, Tile> m_levelMap;
	std::vector<Tile> m_levelMap;

public:
	GameObjects(WindowRenderer& window, Level& level);
	Player* getPlayer();
	std::vector<Tile>& getLevelMap();
	void updateGameObjectStates(double alpha, double prevX, double prevY);

	bool loadMap();
	bool renderMap();
	bool cleanUp();
};