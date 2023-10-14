#pragma once
#include <string>
#include <vector>

#include "Tile.h"
#include "WindowRenderer.h"

class Level 
{
private:
	std::string mapString;
	const int m_numTilesLevelWidth = 50;
	const int m_numTilesLevelHeight = 15;

	const int m_levelWidth = 3200;
	const int m_levelHeight = 960;
	const int m_tileWidth = 64;
	const int m_tileHeight = 64;

	WindowRenderer* m_window;

	std::vector<std::vector<Tile>> m_map;
	SDL_Texture* m_floorTexture;

public:
	Level(std::string stringToMap, WindowRenderer* window);

	std::string getMapString();
	int getLevelWidth();
	int getLevelHeight();
	int getTileLevelWidth();
	int getTileLevelHeight();
	bool renderViewableArea(float offsetX, float offsetY);
	std::vector<std::vector<Tile>>* getMap();

	bool loadMap();
};