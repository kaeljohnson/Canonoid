#pragma once

#include <vector>

#include "WindowRenderer.h"
#include "Entity.h"
#include "State.h"
#include "Tile.h"

class Player : public Entity
{
private:

	// Not really sure how to handle the player moving around the level? For now just have a pointer to the level in here.
	Level* m_level;
	std::vector<std::vector<Tile>>* m_levelMap;

	// If game loop totally dependent on time step then walk velocity needs to be multiplied
	// by something dependent on the frame rate so there is no decline in player velocity between
	// different monitor refresh rates.
	static const int WALK_VELOCITY = 2;

	bool keys[256] = { false };

public:
	Player(int x, int y, float xVel, float yVel, bool physOn, SDL_Texture* player, Level* level, std::vector<std::vector<Tile>>* levelMap);
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
	bool isColliding(std::vector<std::vector<Tile>>* levelMap);
	void render(float offsetX, float offsetY);
};