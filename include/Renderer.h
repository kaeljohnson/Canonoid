#pragma once
#include <SDL.h>
#include <SDL_image.h>

#include "Entity.h"
#include "Tile.h"

class Renderer 
{
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
public:
	Renderer(const char* title, int width, int height);
	SDL_Texture* loadTexture(const char* filePath);
	void clearScreen();
	void render(Entity& entity, const float offsetX, const float offsetY, const float interpolation);
	void render(Tile& tile, const float offsetX, const float offsetY, const float interpolation);
	void display();
	void free();
};