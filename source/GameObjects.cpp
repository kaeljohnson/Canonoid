#include "../include/GameObjects.h"

GameObjects::GameObjects(WindowRenderer& window)
{
	SDL_Texture* playerSprite = window.loadTexture(textureImages::getPlayerPng());
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
