#pragma once

#include <stdio.h>

#include "../include/Entity.h"

Entity::Entity() : m_isCollidable(false)
{
	m_currParentFrame.x = 0;
	m_currParentFrame.y = 0;
	m_currParentFrame.w = 0;
	m_currParentFrame.h = 0;
}
Entity::Entity(SDL_Texture* texture, float xPos, float yPos, float xVel, float yVel, bool physOn, bool isCollidable, float textureStartingX, float textureStartingY, float textureEndingX, float textureEndingY)
	: state(xPos, yPos, xVel, yVel, physOn), m_texture(texture), m_isCollidable(isCollidable)
{
	m_currParentFrame.x = textureStartingX;
	m_currParentFrame.y = textureStartingY;
	m_currParentFrame.w = textureEndingX;  
	m_currParentFrame.h = textureEndingY;
}

void Entity::move()
{
	return;
}

SDL_Texture* Entity::getTexture() const
{
	return m_texture;
}

void Entity::setCurrParentFrame(SDL_Rect& currFrame) 
{
	m_currParentFrame = currFrame;
}

const SDL_Rect& Entity::getCurrFrame() const
{
	return m_currParentFrame;
}

const State& Entity::getState() const
{
	return state;
}

void Entity::free() 
{
	if (m_texture != nullptr) 
	{
		SDL_DestroyTexture(m_texture);
		m_texture = nullptr;
	}
}

void Entity::setStateX(float newXPos, float newXVel)
{
	state.setXPos(newXPos);
	state.setXVel(newXVel);
}

void Entity::setStateY(float newYPos, float newYVel)
{
	state.setYPos(newYPos);
	state.setYVel(newYVel);
}

void Entity::setPrevStateX(float x, float xVel)
{
	state.setPrevXPos(x);
	state.setPrevXVel(xVel);
}

void Entity::setPrevStateY(float y, float yVel)
{
	state.setPrevYPos(y);
	state.setPrevYVel(yVel);
}

void Entity::collision(const Entity& topLeft, const Entity& topRight, const Entity& bottomLeft, const Entity& bottomRight)
{
	if (!topLeft.m_isCollidable && !topRight.m_isCollidable && !bottomLeft.m_isCollidable && !bottomRight.m_isCollidable) return;

	const float xPos = state.getXPos();
	const float xVel = state.getXVel();
	const float yPos = state.getYPos();
	const float yVel = state.getYVel();

	const float width = m_currParentFrame.w;
	const float height = m_currParentFrame.h;

	if (xVel > 0 && yVel > 0)
	{
		bool cornerCollision = collisionX(bottomRight) &&
				               collisionY(bottomRight) &&
				               !collisionX(topRight) &&
				               !collisionY(bottomLeft);

		if (cornerCollision)
		{
			float diffBetweenX = (xPos + width - bottomRight.getState().getXPos());
			float diffBetweenY = ((yPos + height) - bottomRight.getState().getYPos());

			if (diffBetweenX == diffBetweenY)
			{
				setStateY(yPos - yVel, yVel);
				setStateX(xPos - xVel, xVel);
			}
			else if (diffBetweenX > diffBetweenY)
			{
				setStateY(yPos - yVel, yVel);
			}
			else
			{
				setStateX(xPos - xVel, xVel);
			}
		}
		else if (collisionX(topRight) && collisionY(bottomLeft))
		{
			setStateX(xPos - xVel, xVel);
			setStateY(yPos - yVel, yVel);
		}
		else if ((collisionX(topRight) || collisionX(bottomRight)) && !collisionY(bottomLeft))
		{
			setStateX(xPos - xVel, xVel);
		}
		else if ((collisionY(bottomLeft) || collisionY(bottomRight)) && !collisionX(topRight))
		{
			setStateY(yPos - yVel, yVel);
		}
	}
	else if (xVel > 0 && yVel < 0)
	{
		bool cornerCollision = collisionX(topRight) &&
							   collisionY(topRight) &&
							   !collisionX(bottomRight) &&
							   !collisionY(topLeft);

		if (cornerCollision)
		{
			float diffBetweenX = (xPos + width - topRight.getState().getXPos());
			float diffBetweenY = ((topRight.getState().getYPos() + topRight.getCurrFrame().h - yPos));

			if (diffBetweenX == diffBetweenY)
			{
				setStateY(yPos - yVel, yVel);
				setStateX(xPos - xVel, xVel);
			}
			else if (diffBetweenX > diffBetweenY)
			{
				setStateY(yPos - yVel, yVel);
			}
			else
			{
				setStateX(xPos - xVel, xVel);
			}
		}
		else if (collisionY(topLeft) && collisionX(bottomRight))
		{
			setStateX(xPos - xVel, xVel);
			setStateY(yPos - yVel, yVel);
		}
		else if ((collisionX(topRight) || collisionX(bottomRight)) && !collisionY(topLeft))
		{
			setStateX(xPos - xVel, xVel);
		}
		else if ((collisionY(topLeft) || collisionY(topRight)) && !collisionX(bottomRight))
		{
			setStateY(yPos - yVel, yVel);
		}
	}
	else if (xVel < 0 && yVel < 0)
	{
		bool cornerCollision = collisionX(topLeft) &&
			                   collisionY(topLeft) &&
							   !collisionX(topRight) &&
							   !collisionY(bottomLeft);

		if (cornerCollision)
		{
			float diffBetweenX = (topLeft.state.getXPos() + topLeft.getCurrFrame().w - xPos);
			float diffBetweenY = (topLeft.state.getYPos() + topLeft.getCurrFrame().h - yPos);

			if (diffBetweenX == diffBetweenY)
			{
				setStateY(yPos - yVel, yVel);
				setStateX(xPos - xVel, xVel);
			}
			else if (diffBetweenX > diffBetweenY)
			{
				setStateY(yPos - yVel, yVel);
			}
			else
			{
				setStateX(xPos - xVel, xVel);
			}
		}
		else if (collisionX(bottomLeft) && collisionY(topRight))
		{
			setStateX(xPos - xVel, xVel);
			setStateY(yPos - yVel, yVel);
		}
		else if ((collisionX(topLeft) || collisionX(bottomLeft)) && !collisionY(topRight))
		{
			setStateX(xPos - xVel, xVel);
		}
		else if ((collisionY(topLeft) || collisionY(topRight)) && !collisionX(bottomLeft))
		{
			setStateY(yPos - yVel, yVel);
		}
	}
	else if (xVel < 0 && yVel > 0)
	{
		bool cornerCollision = collisionX(bottomLeft) &&
							   collisionY(bottomLeft) &&
							   !collisionX(topLeft) &&
							   !collisionY(bottomRight);

		if (cornerCollision)
		{
			float diffBetweenX = (bottomLeft.getState().getXPos() + bottomLeft.getCurrFrame().w - xPos);
			float diffBetweenY = (yPos + height - bottomLeft.getState().getYPos());

			if (diffBetweenX == diffBetweenY)
			{
				setStateY(yPos - yVel, yVel);
				setStateX(xPos - xVel, xVel);
			}
			else if (diffBetweenX > diffBetweenY)
			{
				setStateY(yPos - yVel, yVel);
			}
			else
			{
				setStateX(xPos - xVel, xVel);
			}
		}
		else if (collisionX(topLeft) && collisionY(bottomRight))
		{
			setStateX(xPos - xVel, xVel);
			setStateY(yPos - yVel, yVel);
		}
		else if ((collisionX(topLeft) || collisionX(bottomLeft)) && !collisionY(bottomRight))
		{
			setStateX(xPos - xVel, xVel);
		}
		else if ((collisionY(bottomLeft) || collisionY(bottomRight)) && !collisionX(topLeft))
		{
			setStateY(yPos - yVel, yVel);
		}
	}	
	else if (yVel < 0)
	{
		if (collisionY(topLeft) && collisionY(topRight))
		{
			setStateY(yPos - yVel, yVel);
			return;
		}

		bool cornerCollisionRight = collisionX(topRight) &&
									collisionY(topRight);

		if (cornerCollisionRight)
		{
			float diffBetweenX = (xPos + width - topRight.getState().getXPos());
			float diffBetweenY = (topRight.getState().getYPos() + topRight.getCurrFrame().h - yPos);

			if (diffBetweenX == diffBetweenY)
			{
				setStateY(yPos - yVel, yVel);
				setStateX(xPos - xVel, xVel);
			}
			else if (diffBetweenX > diffBetweenY)
			{
				setStateY(yPos - yVel, yVel);
			}
			else
			{
				setStateX(xPos - xVel, xVel);
			}
			return;
		}

		bool cornerCollisionLeft = collisionX(topLeft) &&
								   collisionY(topLeft);

		if (cornerCollisionLeft)
		{
			float diffBetweenX = (topLeft.getState().getXPos() + topLeft.getCurrFrame().w - xPos);
			float diffBetweenY = (topLeft.getState().getYPos() + topLeft.getCurrFrame().h - yPos);

			if (diffBetweenX == diffBetweenY)
			{
				setStateY(yPos - yVel, yVel);
				setStateX(xPos - xVel, xVel);
			}
			else if (diffBetweenX > diffBetweenY)
			{
				setStateY(yPos - yVel, yVel);
			}
			else
			{
				setStateX(xPos - xVel, xVel);
			}
			return;
		}
	}
	else if (yVel > 0)
	{
		if (collisionY(bottomLeft) && collisionY(bottomRight))
		{
			setStateY(yPos - yVel, yVel);
			return;
		}

		bool cornerCollisionRight = collisionX(bottomRight) &&
									collisionY(bottomRight);

		if (cornerCollisionRight)
		{
			float diffBetweenX = (xPos + width - bottomRight.getState().getXPos());
			float diffBetweenY = (yPos + height - bottomRight.getState().getYPos());

			if (diffBetweenX == diffBetweenY)
			{
				setStateY(yPos - yVel, yVel);
				setStateX(xPos - xVel, xVel);
			}
			else if (diffBetweenX > diffBetweenY)
			{
				setStateY(yPos - yVel, yVel);
			}
			else
			{
				setStateX(xPos - xVel, xVel);
			}
			return;
		}

		bool cornerCollisionLeft = collisionX(bottomLeft) &&
								   collisionY(bottomLeft);

		if (cornerCollisionLeft)
		{
			float diffBetweenX = (xPos - bottomLeft.getState().getXPos() + bottomLeft.getCurrFrame().w);
			float diffBetweenY = (yPos + height - bottomLeft.getState().getYPos());

			if (diffBetweenX == diffBetweenY)
			{
				setStateY(yPos - yVel, yVel);
				setStateX(xPos - xVel, xVel);
			}
			else if (diffBetweenX > diffBetweenY)
			{
				setStateY(yPos - yVel, yVel);
			}
			else
			{
				setStateX(xPos - xVel, xVel);
			}
			return;
		}
	}
	else if (xVel < 0)
	{
		if (collisionX(bottomLeft) && collisionX(topLeft))
		{
			setStateX(xPos - xVel, xVel);
			return;
		}

		bool cornerCollisionTop = collisionX(topLeft) &&
								  collisionY(topLeft);

		if (cornerCollisionTop)
		{
			float diffBetweenX = (topLeft.getState().getXPos() + topLeft.getCurrFrame().w - xPos);
			float diffBetweenY = (topLeft.getState().getYPos() + topLeft.getCurrFrame().h - yPos);

			if (diffBetweenX == diffBetweenY)
			{
				setStateY(yPos - yVel, yVel);
				setStateX(xPos - xVel, xVel);
			}
			else if (diffBetweenX > diffBetweenY)
			{
				setStateY(yPos - yVel, yVel);
			}
			else
			{
				setStateX(xPos - xVel, xVel);
			}
			return;
		}

		bool cornerCollisionBottom = collisionX(bottomLeft) &&
									 collisionY(bottomLeft);

		if (cornerCollisionBottom)
		{
			float diffBetweenX = (bottomLeft.getState().getXPos() + bottomLeft.getCurrFrame().w - xPos);
			float diffBetweenY = (bottomLeft.getState().getYPos() - yPos + height);

			if (diffBetweenX == diffBetweenY)
			{
				setStateY(yPos - yVel, yVel);
				setStateX(xPos - xVel, xVel);
			}
			else if (diffBetweenX > diffBetweenY)
			{
				setStateY(yPos - yVel, yVel);
			}
			else
			{
				setStateX(xPos - xVel, xVel);
			}
			return;
		}
	}
	else if (xVel > 0)
	{
		if (collisionX(bottomRight) && collisionX(topRight))
		{
			setStateX(xPos - xVel, xVel);
			return;
		}

		bool cornerCollisionTop = collisionX(topRight) &&
								  collisionY(topRight);

		if (cornerCollisionTop)
		{
			float diffBetweenX = (xPos + width - topRight.getState().getXPos());
			float diffBetweenY = (topRight.getState().getYPos() + topRight.getCurrFrame().h - yPos);

			if (diffBetweenX == diffBetweenY)
			{
				setStateY(yPos - yVel, yVel);
				setStateX(xPos - xVel, xVel);
			}
			else if (diffBetweenX > diffBetweenY)
			{
				setStateY(yPos - yVel, yVel);
			}
			else
			{
				setStateX(xPos - xVel, xVel);
			}
			return;
		}

		bool cornerCollisionBottom = collisionX(bottomRight) &&
									 collisionY(bottomRight);

		if (cornerCollisionBottom)
		{
			float diffBetweenX = (xPos + width - bottomRight.getState().getXPos());
			float diffBetweenY = (yPos + height - bottomRight.getState().getYPos());

			if (diffBetweenX == diffBetweenY)
			{
				setStateY(yPos - yVel, yVel);
				setStateX(xPos - xVel, xVel);
			}
			else if (diffBetweenX > diffBetweenY)
			{
				setStateY(yPos - yVel, yVel);
			}
			else
			{
				setStateX(xPos - xVel, xVel);
			}
			return;
		}
	}
}

bool Entity::collisionX(const Entity& toComp)
{
	if (!toComp.m_isCollidable) return false;

	float xPosLeft = state.getXPos();
	float xPosRight = xPosLeft + m_currParentFrame.w;

	const State& toCompState = toComp.getState();
	
	bool sidewaysCollision = xPosRight > toCompState.getXPos() && xPosLeft < toCompState.getXPos() + toComp.getCurrFrame().w;

	if (sidewaysCollision)
	{
		return true;
	}
	return false;
} 

bool Entity::collisionY(const Entity& toComp)
{
	if (!toComp.m_isCollidable) return false;

	float yPosTop = state.getYPos();
	float yPosBottom = yPosTop + m_currParentFrame.h;

	const State& toCompState = toComp.getState();

	bool verticalCollision = yPosTop < toCompState.getYPos() + toComp.getCurrFrame().h && yPosBottom > toCompState.getYPos();

	if (verticalCollision)
	{
		return true;
	}
	return false;
}

// Unused functions below

bool Entity::collision(const Entity& toCompare)
{
	if (toCompare.m_isCollidable == false) return false;

	const State& toCompareState = toCompare.getState();

	float oneLeft = state.getXPos();
	float oneRight = oneLeft + getCurrFrame().w;
	float oneTop = state.getYPos();
	float oneBottom = oneTop - getCurrFrame().h;

	float twoLeft = toCompareState.getXPos();
	float twoRight = twoLeft + toCompare.getCurrFrame().w;
	float twoTop = toCompareState.getYPos();
	float twoBottom = twoTop - toCompare.getCurrFrame().h;

	bool verticalCollision = oneTop > twoBottom && oneBottom < twoTop;
	bool sidewaysCollision = oneRight >= twoLeft && oneLeft <= twoRight;

	if (verticalCollision && sidewaysCollision)
	{
		return true;
	}

	return false;
}