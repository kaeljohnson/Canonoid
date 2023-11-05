#pragma once

#include <string>

#include "../include/Level.h"
#include "../include/WindowRenderer.h"
#include "../include/Levels.h"
#include "../include/Tile.h"

Level::Level(WindowRenderer* window, std::unordered_map<std::string, SDL_Texture*>& levelTextures)
	: ptrWindow(window), ptrFloorTexture(levelTextures.at("floor1")), playerStartingX(0), playerStartingY(0)
{
	levels::getBigPlayground(m_levelDetails);
	loadMap();
}

const std::string& Level::getMapString() const
{
	return m_levelDetails.m_levelString;
}

const float Level::getTileLevelWidth() const
{
	return m_levelDetails.m_levelWidthInTiles;
}

const float Level::getTileLevelHeight() const
{
	return m_levelDetails.m_levelHeightInTiles;
}

const float Level::getLevelWidth() const
{
	return m_levelDetails.m_levelWidthInPixels;
}

const float Level::getLevelHeight() const
{
	return m_levelDetails.m_levelHeightInPixels;
}

const float Level::getTileWidthInPixels() const
{
	return m_levelDetails.m_tileWidthInPixels;
}

const float Level::getTileHeightInPixels() const
{
	return m_levelDetails.m_tileHeightInPixels;
}

bool Level::loadMap()
{
	int currXTile = 0;
	int currYTile = 0;
	std::vector<Tile> tempLayer;

	for (auto& i : m_levelDetails.m_levelString)
	{
		if (currXTile == m_levelDetails.m_levelWidthInTiles)
		{
			currXTile = 0;
			currYTile += 1;

			m_map.push_back(tempLayer);
			tempLayer = {};
		}
		if (i == 'g')
		{
			int xTileCoord = currXTile * m_levelDetails.m_tileWidthInPixels;
			int yTileCoord = currYTile * m_levelDetails.m_tileHeightInPixels;
			tempLayer.push_back(Tile(xTileCoord, yTileCoord, ptrFloorTexture, true, m_levelDetails.m_tileWidthInPixels, m_levelDetails.m_tileHeightInPixels));
		}
		if (i == '-')
		{
			int xTileCoord = currXTile * m_levelDetails.m_tileWidthInPixels;
			int yTileCoord = currYTile * m_levelDetails.m_tileHeightInPixels;
			tempLayer.push_back(Tile(xTileCoord, yTileCoord, nullptr, false, m_levelDetails.m_tileWidthInPixels, m_levelDetails.m_tileHeightInPixels));
		}
		if (i == 'p')
		{
			int xTileCoord = currXTile * m_levelDetails.m_tileWidthInPixels;
			int yTileCoord = currYTile * m_levelDetails.m_tileHeightInPixels;
			playerStartingX = xTileCoord;
			playerStartingY = yTileCoord;
			tempLayer.push_back(Tile(xTileCoord, yTileCoord, nullptr, false, m_levelDetails.m_tileWidthInPixels, m_levelDetails.m_tileHeightInPixels));
		}
		currXTile += 1;
	}

	m_map.push_back(tempLayer);

	return true;
}

bool Level::renderViewableArea(const float offsetX, const float offsetY, const float cameraWidth, const float cameraHeight, const float interpolation)
{
	int firstViewableTileX = (int)(offsetX / 64);
	int firstViewableTileY = (int)(offsetY / 64);

	int lastViewableTileX = firstViewableTileX + (int)(cameraWidth / 64) + 1;
	int lastViewableTileY = firstViewableTileY + (int)(cameraHeight / 64) + 1;

	lastViewableTileX = lastViewableTileX > m_levelDetails.m_levelWidthInTiles ? m_levelDetails.m_levelWidthInTiles : lastViewableTileX;
	lastViewableTileY = lastViewableTileY > m_levelDetails.m_levelHeightInTiles ? m_levelDetails.m_levelHeightInTiles : lastViewableTileY;

	for (int layer = firstViewableTileY; layer < lastViewableTileY; layer++)
	{
		for (int column = firstViewableTileX; column < lastViewableTileX; column++)
		{
			Tile& currTile = m_map[layer][column];
			ptrWindow->render(currTile, offsetX, offsetY, interpolation);
		}
	}

	return true;
}

const std::vector<std::vector<Tile>>& Level::getMap() const
{
	return m_map;
}

const float Level::getPlayerStartingX() const
{
	return playerStartingX;
}

const float Level::getPlayerStartingY() const
{
	return playerStartingY;
}

const LevelDetails& Level::getLevelDetails() const
{
	return m_levelDetails;
}