#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "State.h"

class Entity
{
private:
	SDL_Rect m_currParentFrame;
	SDL_Texture* m_texture = nullptr;

public:
	State state;

	Entity();
	Entity(int xPos, int yPos, float xVel, float yVel, bool physOn, SDL_Texture* texture);

	void setCurrParentFrame(SDL_Rect& currFrame);

	SDL_Texture* getTexture();
	SDL_Rect& getCurrFrame();
	void free();

	// TO-DO: Need a way to either implicitily or explicitly determine if an entity is affected by physics or is not.
	// I.E. Architecture tiles are not affected by physics.
};