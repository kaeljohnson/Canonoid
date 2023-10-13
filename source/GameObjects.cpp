#include "../include/GameObjects.h"
#include "../include/Textures.h"
#include "../include/Tile.h"
#include "../include/Util.h"
#include "../include/Levels.h"
#include "../include/Camera.h"

// Should make this a Singleton.
GameObjects::GameObjects(WindowRenderer* window) : m_window(window), m_offsetX(0), m_offsetY(0)
{
	SDL_Texture* playerSprite = window->loadTexture(textureImages::getPlayerPng());
	m_floorSprite = window->loadTexture(textureImages::getFloor1());

	m_level = new Level(levels::getPlayground());
	loadMap();

	m_player = new Player(400, 200, 0, 0, true, playerSprite, m_level, &m_levelMap);

	Camera::getInstance()->setCameraValues(0, 0, 0, 0, m_level, &m_levelMap);
}

Player* GameObjects::getPlayer()
{
	return m_player;
}

bool GameObjects::loadMap()
{
	int currXTile = 0;
	int currYTile = 0;
	std::vector<Tile> tempLayer;

	for (auto& i : m_level->getMapString())
	{
		if (currXTile == m_level->getTileLevelWidth())
		{
			currXTile = 0;
			currYTile += 1;

			m_levelMap.push_back(tempLayer);
			tempLayer = {};
		}
		if (i == 'g')
		{
			int xTileCoord = currXTile * 64;
			int yTileCoord = currYTile * 64;
			tempLayer.push_back(Tile(xTileCoord, yTileCoord, m_floorSprite, true));
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

void GameObjects::handleUserInput(SDL_Event& e)
{
	getPlayer()->handleMoveInput(e);
}

void GameObjects::moveObjects()
{
	getPlayer()->move();
}

bool GameObjects::renderViewableArea()
{
	for (int x = 0; x < 14; x++)
	{
		for (int y = 0; y < 50; y++)
		{
			Tile& currTile = m_levelMap[x][y];
			m_window->render(currTile, m_offsetX, m_offsetY);
		}
	}

	return true;
}

void GameObjects::moveCamera()
{
	Camera* pCamera = Camera::getInstance();
	pCamera->move(getPlayer()->state.getXPos(), getPlayer()->state.getYPos());
}

void GameObjects::clampCamera()
{
	Camera* pCamera = Camera::getInstance();
	pCamera->clamp(m_offsetX, m_offsetY);
}

bool GameObjects::renderPlayer()
{
	m_window->render(*(getPlayer()), m_offsetX, m_offsetY);

	return true;
}

bool GameObjects::cleanUp()
{
	delete m_player;
	delete m_level;

	return true;
}

std::vector<std::vector<Tile>>& GameObjects::getLevelMap()
{
	return m_levelMap;
}

void GameObjects::setOffsets()
{
	Camera* pCamera = Camera::getInstance();

	m_offsetX = pCamera->getXValue() - (float)util::getScreenWidth() / 2;
	m_offsetY = pCamera->getYValue() - (float)util::getScreenHeight() / 2;
}