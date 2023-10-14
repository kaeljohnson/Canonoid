#pragma once

#include <string>

#include "../include/Level.h"
#include "../include/Textures.h"
#include "../include/WindowRenderer.h"

Level::Level(std::string stringToMap, WindowRenderer* window)
	: mapString(stringToMap), m_window(window)
{
	m_floorTexture = m_window->loadTexture(textureImages::getFloor1());
	loadMap();
}

std::string Level::getMapString()
{
	return mapString;
}

int Level::getTileLevelWidth()
{
	return m_numTilesLevelWidth;
}

int Level::getTileLevelHeight()
{
	return m_numTilesLevelHeight;
}

int Level::getLevelWidth()
{
	return m_levelWidth;
}

int Level::getLevelHeight()
{
	return m_levelHeight;
}

bool Level::loadMap()
{
	int currXTile = 0;
	int currYTile = 0;
	std::vector<Tile> tempLayer;

	for (auto& i : mapString)
	{
		if (currXTile == m_numTilesLevelWidth)
		{
			currXTile = 0;
			currYTile += 1;

			m_map.push_back(tempLayer);
			tempLayer = {};
		}
		if (i == 'g')
		{
			int xTileCoord = currXTile * 64;
			int yTileCoord = currYTile * 64;
			tempLayer.push_back(Tile(xTileCoord, yTileCoord, m_floorTexture, true));
		}
		if (i == '-')
		{
			int xTileCoord = currXTile * 64;
			int yTileCoord = currYTile * 64;
			tempLayer.push_back(Tile(xTileCoord, yTileCoord, nullptr, false));
		}
		currXTile += 1;
	}

	return true;
}

bool Level::renderViewableArea(float offsetX, float offsetY)
{
	for (int x = 0; x < 14; x++)
	{
		for (int y = 0; y < 50; y++)
		{
			Tile& currTile = m_map[x][y];
			m_window->render(currTile, offsetX, offsetY);
		}
	}

	return true;
}

std::vector<std::vector<Tile>>* Level::getMap()
{
	return &m_map;
}