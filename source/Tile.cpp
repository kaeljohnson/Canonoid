#include "../include/Tile.h"

Tile::Tile(int x, int y, SDL_Texture* texture)
	: Entity(x, y, 0, 0, false, texture)
{
	SDL_Rect& blockRect = getCurrFrame();
	blockRect.x = 0;
	blockRect.y = 0;
	blockRect.w = 64;
	blockRect.h = 64;

	setCurrParentFrame(blockRect);
}