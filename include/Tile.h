#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include "State.h"

class Tile
{
private:
	SDL_Rect m_tileFrame;
	SDL_Texture* m_texture = nullptr;
	int m_x;
	int m_y;
	bool m_isCollidable;
	int m_tileWidth;
	int m_tileHeight;
public:
	Tile();
	Tile(int x, int y, SDL_Texture* texture, bool isCollidable, int tileWidth, int tileHeight);

	const int getXPos() const;
	const int getYPos() const;
	const int getTileWidth() const;
	const int getTileHeight() const;
	const bool getIsCollidable() const;
	const SDL_Rect& getTileFrame() const;
	SDL_Texture* getTexture() const;

	void setXPos(float x);
	void setYPos(float y);
};