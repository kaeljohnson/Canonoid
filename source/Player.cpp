#include "../include/Player.h"
#include "../include/Util.h"

#include <stdio.h>

Player::Player(int x, int y, float xVel, float yVel, bool physOn, SDL_Texture* playerSprite)
	: Entity(x, y, xVel, yVel, physOn, playerSprite)
{
	size_t frameIdx = 0;
	size_t xStart = 0;


	// After physics is implemented this will be an entire animation sprite sheet, not just a single player rect.
	SDL_Rect& playerRect = getCurrFrame();
	playerRect.x = 0;
	playerRect.y = 0;
	playerRect.w = 64;
	playerRect.h = 64;


	setCurrParentFrame(playerRect);
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

void Player::move(float deltaTime)
{
	state.setXPos(
		state.getXPos() + state.getXVel() * deltaTime * 100
	);
	state.setYPos(
		state.getYPos() + state.getYVel() * deltaTime * 100
	);

	if (state.getYPos() > util::getScreenHeight() - 70 || state.getYPos() < 0)
		state.setYVel(0);

	if (state.getXPos() < 0 || state.getXPos() + 70 > util::getScreenWidth())
		state.setXVel(0);

}