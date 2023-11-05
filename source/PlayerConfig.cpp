#include "../include/PlayerConfig.h"

PlayerConfig::PlayerConfig(SDL_Texture* playerTexture, float playerStartingX, float playerStartingY, float textureStartX, float textureEndX, float textureStartY, float textureEndY, float playerWalkVelocity, float playerRunVelocity, float playerJumpVelocity, bool physics)
	: m_ptrPlayerTexture(playerTexture), 
	  m_playerStartingX(playerStartingX),
	  m_playerStartingY(playerStartingY),
	  m_textureStartX(textureStartX), 
	  m_textureEndX(textureEndX), 
	  m_textureStartY(textureStartY), 
	  m_textureEndY(textureEndY), 
	  m_playerWalkVelocity(playerWalkVelocity), 
	  m_playerRunVelocity(playerRunVelocity), 
	  m_playerJumpVelocity(playerJumpVelocity),
	  m_physics(physics)
{}
