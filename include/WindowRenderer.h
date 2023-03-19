#pragma once
#include <SDL.h>
#include <SDL_image.h>

#include "Entity.h"
#include "Level.h"

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
	void render(Entity& texture);
	void display();
	void free();
};