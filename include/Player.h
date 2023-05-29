#pragma once

#include "WindowRenderer.h"
#include "Entity.h"
#include "State.h"

class Player : public Entity 
{
private:

	static const int WALK_VELOCITY = 4;

	bool keys[256] = { false };

public:
	Player(int x, int y, float xVel, float yVel, bool physOn, SDL_Texture* player);
	void handleMoveInput(SDL_Event& e);
	
	void startWalkLeft();
	void startWalkRight();
	void endWalkLeft();
	void endWalkRight();
	void goUp();
	void goDown();
	void endGoUp();
	void endGoDown();
	void move(float deltaTime);
};