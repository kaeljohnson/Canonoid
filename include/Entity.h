#pragma once

#include <SDL.h>
#include <SDL_image.h>

class Entity
{
private:
	SDL_Rect m_currParentFrame;
	SDL_Texture* m_texture = nullptr;
public:
	int m_mass;
	int m_xPos;
	int m_yPos;

	Entity();
	Entity(int xPos, int yPos, SDL_Texture* texture);

	void setCurrParentFrame(SDL_Rect& currFrame);

	SDL_Texture* getTexture();
	SDL_Rect& getCurrFrame();
	void free();
};