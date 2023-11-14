#pragma once

#include <SDL.h>
#include <vector>

#include "../include/GameObjects.h"
#include "../include/Entity.h"
#include "../include/Tile.h"
#include "../include/Util.h"
#include "../include/Renderer.h"
#include "../include/PlayerConfig.h"
#include "../include/Camera.h"
#include "../include/Level.h"
#include "../include/State.h"


// should collision detection be handled in here?
GameObjects::GameObjects(Renderer& window, Player* player, Camera& camera, Level& level) : refWindow(window), m_ptrPlayer(player), refCamera(camera), refLevel(level), m_offsetX(0), m_offsetY(0)
{
	// Need easy way to build level. Level building interface should allow user to just pass in a string. Maybe parse a .txt file which must be configured as a rectangle.
	// Then we build the level based on that file. We can hold any user created textures in the textures file. Force tiles to be 64X64?
	// ptrLevel = new Level(&window);

	// m_ptrPlayer = new Player(playerConfig);

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
		// entity->setStateX((entity->getState().getXPos() * alpha + entity->getState().getPrevXPos() * (1.0 - alpha)), entity->getState().getXVel());
		// entity->setStateY((entity->getState().getYPos() * alpha + entity->getState().getPrevYPos() * (1.0 - alpha)), entity->getState().getYVel());

		// entity->setPrevStateX(entity->getState().getXPos(), entity->getState().getXVel());
		// entity->setPrevStateY(entity->getState().getYPos(), entity->getState().getYVel());
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
	const float playerX = playerState.currXPos;
	const float playerY = playerState.currYPos;

	refCamera.move(playerX, playerY);
}

void GameObjects::clampCamera()
{
	refCamera.clamp(m_offsetX, m_offsetY);
}

bool GameObjects::cleanUp()
{
	delete m_ptrPlayer;

	return true;
}

void GameObjects::setOffsets()
{
	m_offsetX = refCamera.getXValue() - (float)util::getScreenWidth() / 2;
	m_offsetY = refCamera.getYValue() - (float)util::getScreenHeight() / 2;
}

void GameObjects::checkCollisions()
{
	for (Entity* entity : collidableEntities)
	{
		const State& entityState = entity->getState();
		const float xPos = entityState.currXPos;
		const float yPos = entityState.currYPos;
		const float xVel = entityState.currXVel;
		const float yVel = entityState.currYVel;

		if (xVel == 0 && yVel == 0) continue;

		const std::vector<std::vector<Tile>>& map = refLevel.getMap();

		int entityTilePosXleft = (int)((xPos) / util::getTileDim());
		int entityTilePosYtop = (int)((yPos) / util::getTileDim());
		int entityTilePosXright = (int)((xPos + entity->getCurrFrame().w - 1) / util::getTileDim());
		int entityTilePosYbottom = (int)((yPos + entity->getCurrFrame().h - 1) / util::getTileDim());

		if (yPos + entity->getCurrFrame().h > refLevel.getLevelHeight() - yVel - 1)
		{
			entity->setCurrStateY((float)refLevel.getLevelHeight() - entity->getCurrFrame().h - 1, 0);
			entityTilePosYbottom = entityTilePosYtop;
		}
		if (yPos < 0)
		{
			entity->setCurrStateY(0, 0);
		}
		if (xPos < 0)
		{
			entity->setCurrStateX(0, 0);
		}
		if (xPos + entity->getCurrFrame().w > refLevel.getLevelWidth() - xVel - 1)
		{

			entity->setCurrStateX((float)refLevel.getLevelWidth() - entity->getCurrFrame().w, 0);
			entityTilePosXright = entityTilePosXleft;
		}

		entity->collision(map[entityTilePosYtop][entityTilePosXleft],
						  map[entityTilePosYtop][entityTilePosXright],
						  map[entityTilePosYbottom][entityTilePosXleft],
						  map[entityTilePosYbottom][entityTilePosXright]);
	}
}

void GameObjects::updatePhysics()
{
	for (Entity* entity : moveableEntities)
	{
		const State& entityState = entity->getState();
		//entity->setPrevStateY(entity->getState().getYPos(), entity->getState().getYVel());
		// if (!entity->onGround)
		if (false)
		{
			entity->setCurrStateY(entityState.currYPos, entityState.currYVel + 0.5f > 6.0f ? 6.0f : entityState.currYVel + .05f);
		}
		else
		{
			entity->setCurrStateY(entityState.currYPos, entityState.currYVel);
		}
	}
}