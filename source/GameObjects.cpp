#pragma once

#include "../include/GameObjects.h"
#include "../include/Textures.h"
#include "../include/Tile.h"
#include "../include/Util.h"
#include "../include/Levels.h"
#include "../include/Camera.h"

GameObjects::GameObjects(WindowRenderer* window) : m_window(window), m_offsetX(0), m_offsetY(0)
{
	SDL_Texture* playerSprite = window->loadTexture(textureImages::getPlayerPng());

	m_level = new Level(levels::getPlayground(), window);
	m_player = new Player(400, 200, 0, 0, true, playerSprite, m_level);

	Camera::getInstance()->setCameraValues(0, 0, 0, 0, m_level);
}

Player* GameObjects::getPlayer()
{
	return m_player;
}

void GameObjects::handleUserInput(SDL_Event& e)
{
	getPlayer()->handleMoveInput(e);
}

void GameObjects::moveObjects()
{
	getPlayer()->move();
}


bool GameObjects::renderObjects()
{
	m_level->renderViewableArea(m_offsetX, m_offsetY);

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