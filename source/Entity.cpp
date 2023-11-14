#pragma once

#include <stdio.h>

#include "../include/Entity.h"
#include "../include/Tile.h"

Entity::Entity() : m_isCollidable(false)
{
	m_currFrame.x = 0;
	m_currFrame.y = 0;
	m_currFrame.w = 0;
	m_currFrame.h = 0;
}
Entity::Entity(SDL_Texture* texture, float xPos, float yPos, float xVel, float yVel, bool physOn, bool isCollidable, int textureStartingX, int textureStartingY, int textureEndingX, int textureEndingY)
	: state(xPos, yPos, xVel, yVel, physOn), m_texture(texture), m_isCollidable(isCollidable)
{
	m_currFrame.x = textureStartingX;
	m_currFrame.y = textureStartingY;
	m_currFrame.w = textureEndingX;
	m_currFrame.h = textureEndingY;
}

void Entity::move(const Tile& topLeft, const Tile& topRight, const Tile& bottomLeft, const Tile& bottomRight)
{
	return;
}

void Entity::move()
{}

SDL_Texture* Entity::getTexture() const
{
	return m_texture;
}

void Entity::setCurrFrame(SDL_Rect& currFrame)
{
	m_currFrame = currFrame;
}

const SDL_Rect& Entity::getCurrFrame() const
{
	return m_currFrame;
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

void Entity::setCurrStateX(float newXPos, float newXVel)
{
	// state.setXPos(newXPos);
	// state.setXVel(newXVel);
	state.currXPos = newXPos;
	state.currXVel = newXVel;
}

void Entity::setCurrStateY(float newYPos, float newYVel)
{
	// state.setYPos(newYPos);
	// state.setYVel(newYVel);
	state.currYPos = newYPos;
	state.currYVel = newYVel;
}

void Entity::setPrevStateX(float x, float xVel)
{
	// state.setPrevXPos(x);
	// state.setPrevXVel(xVel);
	state.prevXPos = x;
	state.prevXVel = xVel;
}

void Entity::setPrevStateY(float y, float yVel)
{
	// state.setPrevYPos(y);
	// state.setPrevYVel(yVel);
	state.prevYPos = y;
	state.prevYVel = yVel;
}

void Entity::setNextStateX(float nextXPos, float nextXVel)
{
	state.nextXPos = nextXPos;
	state.nextXVel = nextXVel;
}
void Entity::setNextStateY(float nextYPos, float nextYVel)
{
	state.nextYPos = nextYPos;
	state.nextYVel = nextYVel;
}

// Collision detection functions below.
// Currently, collision detections involves passing the 4 tiles surrounding the entity into the objects function.
// The collision function returns early if there are no collisions.
// The function checks the velocities and to know what type of collision to check for. Once the type of collision
// is recognized, if there is a collision, the entity "snaps" to the wall that the collision is occuring on.

inline void Entity::handleCornerCollision(const float diffBetweenX, const float diffBetweenY, const Tile& snapToTile)
{
	const float xPos = state.currXPos;
	const float xVel = state.currXVel;
	const float yPos = state.currYPos;
	const float yVel = state.currYVel;

	if (diffBetweenX == diffBetweenY)
	{
		if (yVel > 0)
			snapUp(snapToTile);
		else
			snapDown(snapToTile);

		if (xVel < 0)
			snapRight(snapToTile);
		else
			snapLeft(snapToTile);
	}
	else if (diffBetweenX > diffBetweenY)
	{
		if (yVel > 0)
			snapUp(snapToTile);
		else
			snapDown(snapToTile);

		// Player should maybe starting sliding off?
		onGround = true;
	}
	else
	{
		if (xVel < 0)
			snapRight(snapToTile);
		else
			snapLeft(snapToTile);
	}
}

inline void Entity::snapDown(const Tile& topTile)
{
	setCurrStateY((float)topTile.getYPos() + (float)m_currFrame.h, state.currYVel);
}

inline void Entity::snapUp(const Tile& bottomTile)
{
	setCurrStateY((float)bottomTile.getYPos() - (float)m_currFrame.h, state.currYVel);
}

inline void Entity::snapLeft(const Tile& rightTile)
{
	setCurrStateX((float)rightTile.getXPos() - (float)m_currFrame.w, state.currXVel);
}

inline void Entity::snapRight(const Tile& leftTile)
{
	setCurrStateX((float)leftTile.getXPos() + (float)leftTile.getTileWidth(), state.currXVel);
}

void Entity::collision(const Tile& topLeft, const Tile& topRight, const Tile& bottomLeft, const Tile& bottomRight)
{
	onGround = false;

	if (!topLeft.getIsCollidable() && !topRight.getIsCollidable() && !bottomLeft.getIsCollidable() && !bottomRight.getIsCollidable()) return;

	const float xPos = state.currXPos;
	const float xVel = state.currXVel;
	const float yPos = state.currYPos;
	const float yVel = state.currYVel;

	const float width = (float)m_currFrame.w;
	const float height = (float)m_currFrame.h;

	if (xVel > 0 && yVel > 0)
	{
		bool cornerCollision = collisionX(bottomRight) &&
			collisionY(bottomRight) &&
			!collisionX(topRight) &&
			!collisionY(bottomLeft);

		if (cornerCollision)
		{
			float diffBetweenX = (xPos + width - bottomRight.getXPos());
			float diffBetweenY = ((yPos + height) - bottomRight.getYPos());

			handleCornerCollision(diffBetweenX, diffBetweenY, bottomRight);
		}
		else if (collisionX(topRight) && collisionY(bottomLeft))
		{
			snapLeft(topRight);
			snapUp(bottomRight);
			onGround = true;
		}
		else if ((collisionX(topRight) || collisionX(bottomRight)) && !collisionY(bottomLeft))
		{
			snapLeft(topRight);
		}
		else if ((collisionY(bottomLeft) || collisionY(bottomRight)) && !collisionX(topRight))
		{
			snapUp(bottomLeft);
			onGround = true;
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
			float diffBetweenX = (xPos + width - topRight.getXPos());
			float diffBetweenY = ((topRight.getYPos() + topRight.getTileFrame().h - yPos));

			handleCornerCollision(diffBetweenX, diffBetweenY, topRight);
		}
		else if (collisionY(topLeft) && collisionX(bottomRight))
		{
			snapLeft(bottomRight);
			snapDown(topLeft);

		}
		else if ((collisionX(topRight) || collisionX(bottomRight)) && !collisionY(topLeft))
		{
			snapLeft(bottomRight);
		}
		else if ((collisionY(topLeft) || collisionY(topRight)) && !collisionX(bottomRight))
		{
			snapDown(topLeft);
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
			float diffBetweenX = (topLeft.getXPos() + topLeft.getTileFrame().w - xPos);
			float diffBetweenY = (topLeft.getYPos() + topLeft.getTileFrame().h - yPos);

			handleCornerCollision(diffBetweenX, diffBetweenY, topLeft);
		}
		else if (collisionX(bottomLeft) && collisionY(topRight))
		{
			snapRight(bottomLeft);
			snapDown(topRight);
		}
		else if ((collisionX(topLeft) || collisionX(bottomLeft)) && !collisionY(topRight))
		{
			snapRight(bottomLeft);
		}
		else if ((collisionY(topLeft) || collisionY(topRight)) && !collisionX(bottomLeft))
		{
			snapDown(topRight);
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
			float diffBetweenX = (bottomLeft.getXPos() + bottomLeft.getTileFrame().w - xPos);
			float diffBetweenY = (yPos + height - bottomLeft.getYPos());

			handleCornerCollision(diffBetweenX, diffBetweenY, bottomLeft);
		}
		else if (collisionX(topLeft) && collisionY(bottomRight))
		{
			snapRight(topLeft);
			snapUp(bottomRight);
			onGround = true;
		}
		else if ((collisionX(topLeft) || collisionX(bottomLeft)) && !collisionY(bottomRight))
		{
			snapRight(topLeft);
		}
		else if ((collisionY(bottomLeft) || collisionY(bottomRight)) && !collisionX(topLeft))
		{
			snapUp(bottomLeft);
			onGround = true;
		}
	}
	else if (yVel < 0)
	{
		if (collisionY(topLeft) && collisionY(topRight))
		{
			snapDown(topLeft);
			return;
		}

		bool cornerCollisionRight = collisionX(topRight) &&
			collisionY(topRight);

		if (cornerCollisionRight)
		{
			float diffBetweenX = (xPos + width - topRight.getXPos());
			float diffBetweenY = (topRight.getYPos() + topRight.getTileFrame().h - yPos);

			handleCornerCollision(diffBetweenX, diffBetweenY, topRight);
			return;
		}

		bool cornerCollisionLeft = collisionX(topLeft) &&
			collisionY(topLeft);

		if (cornerCollisionLeft)
		{
			float diffBetweenX = (topLeft.getXPos() + topLeft.getTileFrame().w - xPos);
			float diffBetweenY = (topLeft.getYPos() + topLeft.getTileFrame().h - yPos);

			handleCornerCollision(diffBetweenX, diffBetweenY, topLeft);
			return;
		}
	}
	else if (yVel > 0)
	{
		if (collisionY(bottomLeft) && collisionY(bottomRight))
		{
			snapUp(bottomRight);
			onGround = true;
			return;
		}

		bool cornerCollisionRight = collisionX(bottomRight) && collisionY(bottomRight);

		if (cornerCollisionRight)
		{
			float diffBetweenX = (xPos + width - bottomRight.getXPos());
			float diffBetweenY = (yPos + height - bottomRight.getYPos());

			handleCornerCollision(diffBetweenX, diffBetweenY, bottomRight);
			return;
		}

		bool cornerCollisionLeft = collisionX(bottomLeft) && collisionY(bottomLeft);

		if (cornerCollisionLeft)
		{
			float diffBetweenX = (xPos - bottomLeft.getXPos() + bottomLeft.getTileFrame().w);
			float diffBetweenY = (yPos + height - bottomLeft.getYPos());

			handleCornerCollision(diffBetweenX, diffBetweenY, bottomLeft);
			return;
		}
	}
	else if (xVel < 0)
	{
		if (collisionX(bottomLeft) && collisionX(topLeft))
		{
			snapRight(topLeft);
			return;
		}

		bool cornerCollisionTop = collisionX(topLeft) &&
			collisionY(topLeft);

		if (cornerCollisionTop)
		{
			float diffBetweenX = (topLeft.getXPos() + topLeft.getTileFrame().w - xPos);
			float diffBetweenY = (topLeft.getYPos() + topLeft.getTileFrame().h - yPos);

			handleCornerCollision(diffBetweenX, diffBetweenY, topLeft);
			return;
		}

		bool cornerCollisionBottom = collisionX(bottomLeft) &&
			collisionY(bottomLeft);

		if (cornerCollisionBottom)
		{
			float diffBetweenX = (bottomLeft.getXPos() + bottomLeft.getTileFrame().w - xPos);
			float diffBetweenY = (bottomLeft.getYPos() - yPos + height);

			handleCornerCollision(diffBetweenX, diffBetweenY, bottomLeft);
			return;
		}
	}
	else if (xVel > 0)
	{
		if (collisionX(bottomRight) && collisionX(topRight))
		{
			snapLeft(topRight);
			return;
		}

		bool cornerCollisionTop = collisionX(topRight) &&
			collisionY(topRight);

		if (cornerCollisionTop)
		{
			float diffBetweenX = (xPos + width - topRight.getXPos());
			float diffBetweenY = (topRight.getYPos() + topRight.getTileFrame().h - yPos);

			handleCornerCollision(diffBetweenX, diffBetweenY, topRight);
			return;
		}

		bool cornerCollisionBottom = collisionX(bottomRight) &&
			collisionY(bottomRight);

		if (cornerCollisionBottom)
		{
			float diffBetweenX = (xPos + width - bottomRight.getXPos());
			float diffBetweenY = (yPos + height - bottomRight.getYPos());

			handleCornerCollision(diffBetweenX, diffBetweenY, bottomRight);
			return;
		}
	}
}

bool Entity::collisionX(const Tile& toComp)
{
	if (!toComp.getIsCollidable()) return false;

	const float xPosLeft = state.currXPos;
	const float xPosRight = xPosLeft + m_currFrame.w;

	bool sidewaysCollision = xPosRight > toComp.getXPos() && xPosLeft < toComp.getXPos() + toComp.getTileFrame().w;

	if (sidewaysCollision)
	{
		return true;
	}
	return false;
}

bool Entity::collisionY(const Tile& toComp)
{
	if (!toComp.getIsCollidable()) return false;

	const float yPosTop = state.currYPos;
	const float yPosBottom = yPosTop + m_currFrame.h;

	bool verticalCollision = yPosTop < toComp.getYPos() + toComp.getTileFrame().h && yPosBottom > toComp.getYPos();

	if (verticalCollision)
	{
		return true;
	}
	return false;
}

// Unused functions below

bool Entity::collision(const Tile& toCompare)
{
	if (!toCompare.getIsCollidable()) return false;

	// const State& toCompareState = toCompare.getState();

	const float oneLeft = state.currXPos;
	const float oneRight = oneLeft + m_currFrame.w;
	const float oneTop = state.currYPos;
	const float oneBottom = oneTop - m_currFrame.h;

	const float twoLeft = (float)toCompare.getXPos();
	const float twoRight = twoLeft + toCompare.getTileFrame().w;
	const float twoTop = (float)toCompare.getYPos();
	const float twoBottom = twoTop - toCompare.getTileFrame().h;

	bool verticalCollision = oneTop > twoBottom && oneBottom < twoTop;
	bool sidewaysCollision = oneRight >= twoLeft && oneLeft <= twoRight;

	if (verticalCollision && sidewaysCollision)
	{
		return true;
	}

	return false;
}