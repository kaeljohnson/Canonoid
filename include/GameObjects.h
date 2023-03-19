#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

#include "Player.h"
#include "WindowRenderer.h"
#include "Textures.h"

class GameObjects
{
private:
	Player* m_player;

public:
	GameObjects(WindowRenderer& window);
	Player* getPlayer();
};