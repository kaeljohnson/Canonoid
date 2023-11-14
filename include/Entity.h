#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include "State.h"
#include "Tile.h"

class Entity
{
private:
	SDL_Rect m_currFrame;
	SDL_Texture* m_texture = nullptr;

protected:
	State state;
public:
	bool m_isCollidable;
	bool onGround = false;
	bool onLeftWall = false;
	bool onRightWall = false;
	bool onCeiling = false;

	Entity();
	Entity(SDL_Texture* texture, 
		float xPos, float yPos, 
		float xVel, float yVel, 
		bool physOn, bool isCollidable, 
		int textureStartingX, int textureStartingY, 
		int textureEndingX, int textureEndingY);

	void setCurrFrame(SDL_Rect& currFrame);
	const SDL_Rect& getCurrFrame() const;

	SDL_Texture* getTexture() const;

	// State getters and setters.
	const State& getState() const;
	void setPrevStateX(float x, float xVel);
	void setPrevStateY(float y, float YVel);
	void setCurrStateX(float newX, float newXVel);
	void setCurrStateY(float newY, float newYVel);
	void setNextStateX(float nextXPos, float nextXVel);
	void setNextStateY(float nextYPos, float nextYVel);

	// Movement related functions.
	virtual void move(const Tile& topLeft, const Tile& topRight, const Tile& bottomLeft, const Tile& bottomRight);
	virtual void move();


	// Collision detection below.
	inline void snapDown(const Tile& bottomTile);
	inline void snapUp(const Tile& bottomTile);
	inline void snapLeft(const Tile& bottomTile);
	inline void snapRight(const Tile& bottomTile);
	inline void handleCornerCollision(const float diffBetweenX, const float diffBetweenY, const Tile& snapToTile);
	bool collision(const Tile&);
	void collision(const Tile& topLeft, const Tile& topRight, const Tile& bottomLeft, const Tile& bottomRight);
	bool collisionX(const Tile& toComp);
	bool collisionY(const Tile& toComp);

	void free();
};