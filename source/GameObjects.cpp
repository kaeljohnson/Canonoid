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

void GameObjects::updateGameObjectStates()
{
	// update all the entities states here.
	// Need to distinguish between an object which can be updated and an object which can't 
	// like a wall or the floor.
}
