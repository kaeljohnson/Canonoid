#include "../include/Entity.h"
#include "../include/Util.h"
#include <stdio.h>

Entity::Entity() 
{
	m_currParentFrame.x = 0;
	m_currParentFrame.y = 0;
	m_currParentFrame.w = 0;
	m_currParentFrame.h = 0;

	m_isCollidable = false;
}
Entity::Entity(int xPos,int yPos, float xVel, float yVel, bool physOn, SDL_Texture* texture, bool isCollidable) 
	: state(xPos, yPos, xVel, yVel, physOn), m_texture(texture), m_isCollidable(isCollidable)
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

const bool Entity::collision(Entity& toCompare)
{
	if (toCompare.m_isCollidable == false) return false;

	float oneLeft = state.getXPos();
	float oneRight = state.getXPos() + getCurrFrame().w;
	float twoLeft = toCompare.state.getXPos();
	float twoRight = toCompare.state.getXPos() + toCompare.getCurrFrame().w;

	float oneTop = state.getYPos();
	float oneBottom = state.getYPos() - getCurrFrame().h;
	float twoTop = toCompare.state.getYPos();
	float twoBottom = toCompare.state.getYPos() - toCompare.getCurrFrame().h;

	bool topBottomCollision = oneTop > twoBottom && oneBottom < twoTop;
	bool sidewaysCollision = oneRight >= twoLeft && oneLeft <= twoRight;

	if (topBottomCollision && sidewaysCollision)
	{
		return true;
	}
	return false;
}