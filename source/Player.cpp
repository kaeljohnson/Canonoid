#pragma once

#include "../include/Player.h"
#include "../include/Util.h"

#include <stdio.h>
#include <unordered_map>

Player::Player() : Entity() {}

Player::Player(int x, int y, float xVel, float yVel, bool physOn, SDL_Texture* playerSprite, Level* level)
	: Entity(x, y, xVel, yVel, physOn, playerSprite, false)
{
	size_t frameIdx = 0;
	size_t xStart = 0;

	// After physics is implemented this will be an entire animation sprite sheet, not just a single player rect.
	SDL_Rect& playerRect = getCurrFrame();
	playerRect.x = 8;
	playerRect.y = 0;
	playerRect.w = 48;
	playerRect.h = 64;

	m_level = level;
}

void Player::handleMoveInput(SDL_Event& e)
{
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		keys[e.key.keysym.sym] = true;
		switch (e.key.keysym.sym)
		{
		case SDLK_a:
			startWalkLeft();
			break;
		case SDLK_d:
			startWalkRight();
			break;
		case SDLK_w:
			goUp();
			break;
		case SDLK_s:
			goDown();
			break;
		}
	}
	if (e.type == SDL_KEYUP && e.key.repeat == 0)
	{
		keys[e.key.keysym.sym] = false;
		switch (e.key.keysym.sym)
		{
		case SDLK_a:
		{
			if (keys[SDLK_d] == true)
				startWalkRight();
			else
				endWalkLeft();
			break;
		}
		case SDLK_d:
		{
			if (keys[SDLK_a] == true)
				startWalkLeft();
			else
				endWalkRight();
			break;
		}
		case SDLK_w:
		{
			if (keys[SDLK_s] == true)
				goDown();
			else
				endGoUp();
			break;
		}
		case SDLK_s:
		{
			if (keys[SDLK_w] == true)
				goUp();
			else
				endGoDown();
			break;
		}
		}
	}
}

void Player::startWalkRight()
{
	state.setXVel(WALK_VELOCITY);
}

void Player::startWalkLeft()
{
	state.setXVel(-WALK_VELOCITY);
}

void Player::goDown()
{
	state.setYVel(WALK_VELOCITY);
}

void Player::goUp()
{
	state.setYVel(-WALK_VELOCITY);
}

void Player::endGoDown()
{
	state.setYVel(0);
}

void Player::endGoUp()
{
	state.setYVel(0);
}

void Player::endWalkRight()
{
	state.setXVel(0);
}

void Player::endWalkLeft()
{
	state.setXVel(0);
}

void Player::move()
{
	int levelHeight = m_level->getLevelHeight();
	int levelWidth = m_level->getLevelWidth();

	if (state.getYPos() + 64 > levelHeight)
	{
		state.setYVel(0);
		state.setYPos(state.getYPos() - WALK_VELOCITY);
	}

	if (state.getYPos() < 64)
	{
		state.setYVel(0);
		state.setYPos(state.getYPos() + WALK_VELOCITY);
	}

	if (state.getXPos() < 64)
	{

		state.setXVel(0);
		state.setXPos(state.getXPos() + WALK_VELOCITY);

	}

	if (state.getXPos() + 64 > levelWidth)
	{
		state.setXVel(0);
		state.setXPos(state.getXPos() - WALK_VELOCITY);
	}

	state.setXPos(
		state.getXPos() + state.getXVel() * util::getTimeDelta() * 100
	);

	if (isColliding())
	{
		state.setXPos(
			state.getXPos() - (state.getXVel()) * util::getTimeDelta() * 100
		);
	}

	state.setYPos(
		state.getYPos() + state.getYVel() * util::getTimeDelta() * 100
	);

	if (isColliding())
	{
		state.setYPos(
			state.getYPos() - (state.getYVel()) * util::getTimeDelta() * 100
		);
	}
}

bool Player::isColliding()
{
	for (auto& layer : *(m_level->getMap()))
	{
		for (auto& tile : layer)
		{
			if (collision(tile))
			{
				return true;
			}
		}
	}
	return false;
}

void Player::render(float offsetX, float offsetY)
{
	state.setXPos( state.getXPos() - offsetX );
	state.setYPos( state.getYPos() - offsetY );
}