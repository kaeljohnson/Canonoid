#pragma once

#include <SDL.h>
#include <vector>

#include "Entity.h"
#include "PlayerConfig.h"

class Player : public Entity
{
private:

	// If game loop totally dependent on time step then walk velocity needs to be multiplied
	// by something dependent on the frame rate so there is no decline in player velocity between
	// different monitor refresh rates.

	const float m_walkVel;

	bool keys[256] = { false };

public:
	Player(PlayerConfig& playerConfig);
	void handleMoveInput(SDL_Event& e);
	void move();
	// void move(const Tile& topLeft, const Tile& topRight, const Tile& bottomLeft, const Tile& bottomRight);
	void render(float offsetX, float offsetY);

	Player(const Player& camera) = delete;
	Player& operator=(const Player&) = delete;
	Player(Player&&) = delete;
	Player& operator=(Player&&) = delete;

};