#include "../include/Entity.h"
#include "../include/Util.h"
#include <stdio.h>

Entity::Entity() 
{
	m_currParentFrame.x = 0;
	m_currParentFrame.y = 0;
	m_currParentFrame.w = 0;
	m_currParentFrame.h = 0;
}
Entity::Entity(int xPos,int yPos, float xVel, float yVel, bool physOn, SDL_Texture* texture) 
	: state(xPos, yPos, xVel, yVel, physOn), m_texture(texture)
{
	m_currParentFrame.x = 0;
	m_currParentFrame.y = 0;
	m_currParentFrame.w = 0;
	m_currParentFrame.h = 0;
}

SDL_Texture* Entity::getTexture()
{
	return m_texture;
}

void Entity::setCurrParentFrame(SDL_Rect& currFrame) 
{
	m_currParentFrame = currFrame;
}

SDL_Rect& Entity::getCurrFrame() 
{
	return m_currParentFrame;
}

void Entity::free() 
{
	if (m_texture != nullptr) 
	{
		SDL_DestroyTexture(m_texture);
		m_texture = nullptr;
	}
}