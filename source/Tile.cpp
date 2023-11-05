#pragma once

#include "../include/Tile.h"

Tile::Tile() : Entity() {}

Tile::Tile(float x, float y, SDL_Texture* texture, bool isCollidable, float tileWidth, float tileHeight)
	: Entity(texture, x, y, 0, 0, false, isCollidable, 0, 0, tileWidth, tileHeight)
{
}