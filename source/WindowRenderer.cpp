#include "../include/WindowRenderer.h"
#include "../include/Entity.h"
#include "../include/Tile.h"
#include "../include/Util.h"

#include <stdio.h>

WindowRenderer::WindowRenderer(const char* windowTitle, int pixelWidth, int pixelHeight) 
	: window ( nullptr ), renderer ( nullptr )
{
	window = SDL_CreateWindow(
		windowTitle, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, pixelWidth, pixelHeight, SDL_WINDOW_SHOWN
	);
	if (window == nullptr)
	{
		printf("Window not created! SDL_Error: %s\n", SDL_GetError());
	}
	
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) 
	{
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
	}
	SDL_SetRenderDrawColor(renderer, 'd3', 'd3', 'd3', SDL_ALPHA_OPAQUE);
}

SDL_Texture* WindowRenderer::loadTexture(const char* filePath)
{
	SDL_Texture* texture = nullptr;
	texture = IMG_LoadTexture(renderer, filePath);
	if (texture == nullptr)
	{
		printf("Failed to load texture. SDL Error: %s\n", SDL_GetError());
	}
	return texture;
}

void WindowRenderer::cleanWindow() 
{
	SDL_DestroyWindow(window);
}

void WindowRenderer::clearScreen() 
{
	SDL_RenderClear(renderer);
}

void WindowRenderer::render(Entity& entity, float offsetX, float offsetY) 
{
	SDL_Rect src = { entity.getCurrFrame().x, entity.getCurrFrame().y, entity.getCurrFrame().w, entity.getCurrFrame().h };
	// src.x = entity.getCurrFrame().x;
	// src.y = entity.getCurrFrame().y;
	// src.w = entity.getCurrFrame().w;
	// src.h = entity.getCurrFrame().h;

	SDL_Rect dst = { entity.state.getXPos() - offsetX, entity.state.getYPos() - offsetY, entity.getCurrFrame().w, entity.getCurrFrame().h };
	// dst.x = entity.state.getXPos();
	// dst.y = entity.state.getYPos();
	// dst.w = entity.getCurrFrame().w;
	// dst.h = entity.getCurrFrame().h;

	SDL_RenderCopy(renderer, entity.getTexture(), &src, &dst);
}

void WindowRenderer::display() 
{
	SDL_RenderPresent(renderer);
}

void WindowRenderer::free() 
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = nullptr;
	renderer = nullptr;
}