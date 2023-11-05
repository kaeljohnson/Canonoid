#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include "State.h"

class Entity
{
private:
	SDL_Rect m_currParentFrame;
	SDL_Texture* m_texture = nullptr;

protected:
	State state;
public:
	bool m_isCollidable;

	Entity();
	Entity(SDL_Texture* texture, 
		float xPos, float yPos, 
		float xVel, float yVel, 
		bool physOn, bool isCollidable, 
		float textureStartingX, float textureStartingY, 
		float textureEndingX, float textureEndingY);

	void setCurrParentFrame(SDL_Rect& currFrame);

	SDL_Texture* getTexture() const;
	const SDL_Rect& getCurrFrame() const;
	const State& getState() const;

	void setPrevStateX(float x, float xVel);
	void setPrevStateY(float y, float YVel);
	void setStateX(float newX, float newXVel);
	void setStateY(float newY, float newYVel);

	virtual void move();

	bool collision(const Entity&);
	void collision(const Entity& topLeft, const Entity& topRight, const Entity& bottomLeft, const Entity& bottomRight);
	bool collisionX(const Entity& toComp);
	bool collisionY(const Entity& toComp);

	void free();
};