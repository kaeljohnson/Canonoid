#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include "Entity.h"

class Tile : public Entity
{
private:
	SDL_Texture* m_texture = nullptr;
public:
	Tile();
	Tile(float x, float y, SDL_Texture* texture, bool isCollidable, float tileWidth, float tileHeight);
};