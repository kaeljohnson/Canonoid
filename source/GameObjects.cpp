#pragma once

#include "../include/GameObjects.h"
#include "../include/Tile.h"
#include "../include/Util.h"
#include "../include/Levels.h"
#include "../include/Camera.h"
#include "../include/PlayerConfig.h"


// should collision detection be handled in here?
GameObjects::GameObjects(WindowRenderer& window, PlayerConfig& playerConfig, Camera& camera, Level& level) : refWindow(window), refCamera(camera), refLevel(level), m_offsetX(0), m_offsetY(0)
{
	// Need easy way to build level. Level building interface should allow user to just pass in a string. Maybe parse a .txt file which must be configured as a rectangle.
	// Then we build the level based on that file. We can hold any user created textures in the textures file. Force tiles to be 64X64?
	// ptrLevel = new Level(&window);

	m_ptrPlayer = new Player(playerConfig);

	collidableEntities.push_back(m_ptrPlayer);
	moveableEntities.push_back(m_ptrPlayer);
}

Player* GameObjects::getPlayer()
{
	return m_ptrPlayer;
}

void GameObjects::handleUserInput(SDL_Event& e)
{
	getPlayer()->handleMoveInput(e);
}

void GameObjects::moveObjects()
{
	for (Entity* entity : moveableEntities)
	{
		
		entity->move();
	}
}

void GameObjects::interpolateObjectStates(float alpha)
{
	// currentState* alpha +
	//	previousState * (1.0 - alpha);

	for (Entity* entity : moveableEntities)
	{
		entity->setStateX((entity->getState().getXPos() * alpha + entity->getState().getPrevXPos() * (1.0 - alpha)), entity->getState().getXVel());
		entity->setStateY((entity->getState().getYPos() * alpha + entity->getState().getPrevYPos() * (1.0 - alpha)), entity->getState().getYVel());

		entity->setPrevStateX(entity->getState().getXPos(), entity->getState().getXVel());
		entity->setPrevStateY(entity->getState().getYPos(), entity->getState().getYVel());
	}
}

bool GameObjects::renderObjects(const float interpolation)
{
	refLevel.renderViewableArea(m_offsetX, m_offsetY, refCamera.getWidth(), refCamera.getHeight(), interpolation);
	refWindow.render(*m_ptrPlayer, m_offsetX, m_offsetY, interpolation);

	return true;
}

void GameObjects::moveCamera()
{
	const State& playerState = getPlayer()->getState();
	const float playerX = playerState.getXPos();
	const float playerY = playerState.getYPos();

	refCamera.move(playerX, playerY);
}

void GameObjects::clampCamera()
{
	refCamera.clamp(m_offsetX, m_offsetY);
}

bool GameObjects::cleanUp()
{
	delete m_ptrPlayer;
	// delete ptrLevel;

	return true;
}

void GameObjects::setOffsets()
{
	m_offsetX = refCamera.getXValue() - (float)util::getScreenWidth() / 2;
	m_offsetY = refCamera.getYValue() - (float)util::getScreenHeight() / 2;
}

const float GameObjects::getCurrentOffsetX() const
{
	return m_offsetX;
}

const float GameObjects::getCurrentOffsetY() const
{
	return m_offsetY;
}

void GameObjects::checkCollisions()
{
	for (Entity* entity : collidableEntities)
	{
		const State& entityState = entity->getState();
		const float xPos = entityState.getXPos();
		const float yPos = entityState.getYPos();
		const float xVel = entityState.getXVel();
		const float yVel = entityState.getYVel();

		if (entityState.getXVel() == 0 && entityState.getYVel() == 0) continue;

		const std::vector<std::vector<Tile>>& map = refLevel.getMap();

		const int entityTilePosXleft = (int)(xPos / 64);
		const int entityTilePosYtop = (int)(yPos / 64);
		const int entityTilePosXright = (int)((xPos + entity->getCurrFrame().w) / 64);
		const int entityTilePosYbottom = (int)((yPos + entity->getCurrFrame().h) / 64);

		const int tileLevelWidth = refLevel.getTileLevelWidth();
		const int tileLevelHeight = refLevel.getTileLevelHeight();
		
		if (yPos + entity->getCurrFrame().h > refLevel.getLevelHeight() - yVel - 1)
		{
			entity->setStateY(yPos - yVel, 0);
		}
		if (yPos < 1)
		{
			entity->setStateY(yPos - yVel, 0);
		}
		if (xPos < 0)
		{
			entity->setStateX(xPos - xVel, 0);
		}
		if (xPos + entity->getCurrFrame().w > refLevel.getLevelWidth() - xVel - 1)
		{
			entity->setStateX(xPos - xVel, 0);
		}

		entity->collision(map[entityTilePosYtop][entityTilePosXleft], 
						  map[entityTilePosYtop][entityTilePosXright], 
						  map[entityTilePosYbottom][entityTilePosXleft], 
						  map[entityTilePosYbottom][entityTilePosXright]);
	}
}