#pragma once

#include "WindowRenderer.h"
#include "Entity.h"

class Tile : public Entity
{
private:
	//SDL_Rect m_currFrame;
	SDL_Texture* m_texture = nullptr;
public:
	Tile(int x, int y, SDL_Texture* texture);
};