#pragma once
#include <SDL.h>
#include <SDL_image.h>

#include "Entity.h"

class WindowRenderer 
{
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
public:
	WindowRenderer(const char* title, int width, int height);
	SDL_Texture* loadTexture(const char* filePath);
	void cleanWindow();
	void clearScreen();
	void render(Entity& entity, const float offsetX, const float offsetY, const float interpolation);
	void display();
	void free();
};