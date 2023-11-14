#pragma once

#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>

#include "../include/Renderer.h"
#include "../include/Entity.h"
#include "../include/Tile.h"
#include "../include/State.h"


Renderer::Renderer(const char* windowTitle, int pixelWidth, int pixelHeight) 
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

SDL_Texture* Renderer::loadTexture(const char* filePath)
{
	SDL_Texture* texture = nullptr;
	texture = IMG_LoadTexture(renderer, filePath);
	if (texture == nullptr)
	{
		printf("Failed to load texture. SDL Error: %s\n", SDL_GetError());
	}
	return texture;
}

void Renderer::clearScreen() 
{
	SDL_RenderClear(renderer);
}

void Renderer::render(Entity& entity, const float offsetX, const float offsetY, const float interpolation) 
{
	const State& entityState = entity.getState();

	SDL_Rect src = { entity.getCurrFrame().x, entity.getCurrFrame().y, entity.getCurrFrame().w, entity.getCurrFrame().h };

	bool interpolationOff = true;

	SDL_Rect dst;

	if (interpolationOff)
	dst = {(int)entityState.currXPos - (int)offsetX,
		(int)entityState.currYPos - (int)offsetY, 
		entity.getCurrFrame().w, 
		entity.getCurrFrame().h};
	else
	dst = {(int)((entityState.currXPos - offsetX) * interpolation + ((entityState.prevXPos - offsetX) * (1.0 - interpolation))),
		(int)((entityState.currYPos - offsetY) * interpolation + ((entityState.prevYPos - offsetY) * (1.0 - interpolation))),
		entity.getCurrFrame().w,
		entity.getCurrFrame().h };

	// entity.setPrevStateX(entityState.getXPos(), 0);
	// entity.setPrevStateY(entityState.getYPos(), 0);

	SDL_RenderCopy(renderer, entity.getTexture(), &src, &dst);
}

void Renderer::render(Tile& tile, const float offsetX, const float offsetY, const float interpolation)
{
	// const State& entityState = entity.getState();

	// SDL_Rect src = { entity.getCurrFrame().x, entity.getCurrFrame().y, entity.getCurrFrame().w, entity.getCurrFrame().h };
	SDL_Rect src = { tile.getTileFrame().x, tile.getTileFrame().y, tile.getTileFrame().w, tile.getTileFrame().h };

	bool interpolationOff = true;

	SDL_Rect dst;

	dst = { (int)tile.getXPos() - (int)offsetX,
			(int)tile.getYPos() - (int)offsetY,
			tile.getTileFrame().w,
			tile.getTileFrame().h };

	// entity.setPrevStateX(entityState.getXPos(), 0);
	// entity.setPrevStateY(entityState.getYPos(), 0);

	SDL_RenderCopy(renderer, tile.getTexture(), &src, &dst);
}

void Renderer::display() 
{
	SDL_RenderPresent(renderer);
}

void Renderer::free() 
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = nullptr;
	renderer = nullptr;
}