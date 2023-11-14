#pragma once

#include "../include/Tile.h"
#include "../include/Util.h"

Tile::Tile() 
	: m_texture(nullptr), m_x(0), m_y(0), m_isCollidable(false), m_tileWidth(0), m_tileHeight(0) {}

Tile::Tile(int x, int y, SDL_Texture* texture, bool isCollidable, int tileWidth, int tileHeight)
	: m_texture(texture), m_x(x), m_y(y), m_isCollidable(isCollidable), m_tileWidth(tileWidth), m_tileHeight(tileHeight)
	// : Entity(texture, x, y, 0, 0, false, isCollidable, 0, 0, tileWidth, tileHeight)
{
	m_tileFrame.x = 0;
	m_tileFrame.y = 0;
	m_tileFrame.w = util::getTileDim();
	m_tileFrame.h = util::getTileDim();
}

const int Tile::getXPos() const
{
	return m_x;
}

const int Tile::getYPos() const
{
	return m_y;
}

const int Tile::getTileWidth() const
{
	return m_tileWidth;
}

const int Tile::getTileHeight() const
{
	return m_tileHeight;
}

const bool Tile::getIsCollidable() const
{
	return m_isCollidable;
}

const SDL_Rect& Tile::getTileFrame() const
{
	return m_tileFrame;
}

SDL_Texture* Tile::getTexture() const
{
	return m_texture;
}

void Tile::setXPos(float x)
{
	m_x = (int)x;
}

void Tile::setYPos(float y)
{
	m_y = (int)y;
}