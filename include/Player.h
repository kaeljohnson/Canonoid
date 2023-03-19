#pragma once

#include "WindowRenderer.h"
#include "Entity.h"

class Player : public Entity 
{
private:

	bool keys[256] = { false };

public:
	Player(int x, int y, SDL_Texture* player);
	void handleMoveInput(SDL_Event& e);
	
	void move(float deltaTime);
};