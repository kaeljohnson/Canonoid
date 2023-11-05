#pragma once

#include <stdio.h>

#include "../include/Player.h"
#include "../include/PlayerConfig.h"

Player::Player(PlayerConfig& playerConfig)
	  : m_walkVel(playerConfig.m_playerWalkVelocity),
		Entity(playerConfig.m_ptrPlayerTexture, 
		       playerConfig.m_playerStartingX,
		       playerConfig.m_playerStartingY, 
		       0, 
		       0, 
		       true, 
		       false, 
		       playerConfig.m_textureStartX, 
		       playerConfig.m_textureStartY, 
		       playerConfig.m_textureEndX, 
		       playerConfig.m_textureEndY)
{}

void Player::handleMoveInput(SDL_Event& e)
{
	if (e.type == SDL_KEYDOWN&& e.key.repeat == 0)
	{
		keys[e.key.keysym.sym] = true;
		switch (e.key.keysym.sym)
		{
		case SDLK_a:
			state.setXVel(-m_walkVel);
			break;
		case SDLK_d:
			state.setXVel(m_walkVel);
			break;
		case SDLK_w:
			state.setYVel(-m_walkVel);
			break;
		case SDLK_s:
			state.setYVel(m_walkVel);
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
				state.setXVel(m_walkVel);
			else
				state.setXVel(0);
			break;
		}
		case SDLK_d:
		{
			if (keys[SDLK_a] == true)
				state.setXVel(-m_walkVel);
			else
				state.setXVel(0);
			break;
		}
		case SDLK_w:
		{
			if (keys[SDLK_s] == true)
				state.setYVel(m_walkVel);
			else
				state.setYVel(0);
			break;
		}
		case SDLK_s:
		{
			if (keys[SDLK_w] == true)
				state.setYVel(-m_walkVel);
			else
				state.setYVel(0);
			break;
		}
		}
	}
}

void Player::move()
{
	state.setXPos(
		state.getXPos() + state.getXVel()
	);

	state.setYPos(
		state.getYPos() + state.getYVel()
	);
}

void Player::render(float offsetX, float offsetY)
{
	state.setXPos( state.getXPos() - offsetX );
	state.setYPos( state.getYPos() - offsetY );
}