#pragma once

#include <SDL.h>
#include <SDL_image.h>

class PlayerConfig
{
public:
	SDL_Texture* m_ptrPlayerTexture;

	const float m_playerStartingX;
	const float m_playerStartingY;

	const int m_textureStartX;
	const int m_textureEndX;
	const int m_textureStartY;
	const int m_textureEndY;

	const float m_playerWalkVelocity;
	const float m_playerRunVelocity;
	const float m_playerJumpVelocity;

	const bool m_physics;

	PlayerConfig(SDL_Texture* playerTexture, 
		         float playerStartingX, 
		         float playerStartingY, 
				 int textureStartX, 
		         int textureEndX, 
		         int textureStartY, 
		         int textureEndY, 
		         float playerWalkVelocity, 
		         float playerRunVelocity, 
		         float playerJumpVelocity, 
		         bool physics);
};