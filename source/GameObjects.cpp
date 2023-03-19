#include "../include/GameObjects.h"

GameObjects::GameObjects(WindowRenderer& window)
{
	SDL_Texture* playerSprite = window.loadTexture(textureImages::getPlayerPng());
	m_player = new Player(0, 0, playerSprite);
}

Player* GameObjects::getPlayer()
{
	return m_player;
}

