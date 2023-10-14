#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <vector>

#include "Entity.h"
#include "Tile.h"
#include "Level.h"

class Player : public Entity
{
private:

	// Not really sure how to handle the player moving around the level? For now just have a pointer to the level in here.
	Level* m_level;

	// If game loop totally dependent on time step then walk velocity needs to be multiplied
	// by something dependent on the frame rate so there is no decline in player velocity between
	// different monitor refresh rates.
	const int WALK_VELOCITY = 2;

	bool keys[256] = { false };

public:
	Player();
	Player(int x, int y, float xVel, float yVel, bool physOn, SDL_Texture* player, Level* level);
	void handleMoveInput(SDL_Event& e);
	
	void startWalkLeft();
	void startWalkRight();
	void endWalkLeft();
	void endWalkRight();
	void goUp();
	void goDown();
	void endGoUp();
	void endGoDown();
	void move();
	bool isColliding();
	void render(float offsetX, float offsetY);
};