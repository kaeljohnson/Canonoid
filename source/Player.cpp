#pragma once

#include <SDL.h>

#include "../include/Player.h"
#include "../include/PlayerConfig.h"
#include "../include/Entity.h"

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
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		keys[e.key.keysym.sym] = true;
		switch (e.key.keysym.sym)
		{
		case SDLK_a:
			state.currXVel = -m_walkVel;
			break;
		case SDLK_d:
			state.currXVel = m_walkVel;
			break;
		case SDLK_w:
			state.currYVel = -m_walkVel;
			break;
		case SDLK_s:
			state.currYVel = m_walkVel;
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
				state.currXVel = m_walkVel;
			else
				state.currXVel = 0;
			break;
		}
		case SDLK_d:
		{
			if (keys[SDLK_a] == true)
				state.currXVel =-m_walkVel;
			else
				state.currXVel = 0;
			break;
		}
		case SDLK_w:
		{
			if (keys[SDLK_s] == true)
				state.currYVel = m_walkVel;
			else
				state.currYVel = 0;
			break;
		}
		case SDLK_s:
		{
			if (keys[SDLK_w] == true)
				state.currYVel = -m_walkVel;
			else
				state.currYVel = 0;
			break;
		}
		case SDLK_SPACE:
		{
			state.currYVel = -2.5;
		}
		}
	}
}

void Player::move()
{
	state.currXPos = state.currXPos + state.currXVel;
	state.currYPos = state.currYPos + state.currYVel;
}

void Player::render(float offsetX, float offsetY)
{
	state.currXPos = state.currXPos - offsetX;
	state.currYPos = state.currYPos - offsetY;
}