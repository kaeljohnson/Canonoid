#pragma once

#include <SDL.h>
#include <SDL_image.h>

class PlayerConfig
{
public:
	SDL_Texture* m_ptrPlayerTexture;

	const float m_playerStartingX;
	const float m_playerStartingY;

	const float m_textureStartX;
	const float m_textureEndX;
	
	const float m_textureStartY;
	const float m_textureEndY;

	const float m_playerWalkVelocity;
	const float m_playerRunVelocity;
	const float m_playerJumpVelocity;

	const bool m_physics;

	PlayerConfig(SDL_Texture* playerTexture, 
		         float playerStartingX, 
		         float playerStartingY, 
				 float textureStartX, 
		         float textureEndX, 
		         float textureStartY, 
		         float textureEndY, 
		         float playerWalkVelocity, 
		         float playerRunVelocity, 
		         float playerJumpVelocity, 
		         bool physics);
};