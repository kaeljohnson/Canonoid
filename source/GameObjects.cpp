#include "../include/GameObjects.h"
#include "../include/Textures.h"
#include "../include/Tile.h"

GameObjects::GameObjects(WindowRenderer& window, Level& level) : m_window(window), m_level(level)
{
	SDL_Texture* playerSprite = window.loadTexture(textureImages::getPlayerPng());
	m_floorSprite = window.loadTexture(textureImages::getFloor1());
	m_player = new Player(0, 0, 0, 0, true, playerSprite);
}

Player* GameObjects::getPlayer()
{
	return m_player;
}

void GameObjects::updateGameObjectStates(double alpha, double prevX, double prevY)
{
	// update all the entities states here.
	// Need to distinguish between an object which can be updated and an object which can't 
	// like a wall or the floor.

	// for all objects on screen, update physics with interpolation equation.
	//getPlayer()->move(deltaTime);
	//currentState* alpha + previousState * (1.0 - alpha);
	//getPlayer()->state.setXPos( getPlayer()->state.getXPos() * alpha + prevX * (1.0 - alpha) );
	//getPlayer()->state.setYPos( getPlayer()->state.getYPos() * alpha + prevY * (1.0 - alpha) );
}


bool GameObjects::loadMap()
{
	int tempX = 0;
	int tempY = 0;

	//SDL_Texture* floor1 = m_window.loadTexture(textureImages::getFloor1());

	for (auto& i : m_level.getMapString())
	{
		if (tempX == 3200)
		{
			tempX = 0;
			tempY += 64;
		}
		if (i == 'g')
		{
			Tile floor(tempX, tempY, m_floorSprite);
			m_window.render(floor);
		}
		tempX += 64;
	}

	return false;
}
