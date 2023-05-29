#include "../include/Tile.h"

Tile::Tile(int x, int y, SDL_Texture* texture)
	: Entity(x, y, 0, 0, false, texture)
{
	m_currFrame.x = 0;
	m_currFrame.y = 0;
	m_currFrame.w = 48;
	m_currFrame.h = 48;

	setCurrParentFrame(m_currFrame);
}