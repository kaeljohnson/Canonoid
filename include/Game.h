#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

#include "WindowRenderer.h"
#include "GameObjects.h"

class Game 
{
private:

	bool running;

	WindowRenderer* m_window;
	GameObjects* m_gameObjects;

	Game();
	static Game* pInstance;

public:
	static Game* getInstance();

	void initialize(WindowRenderer* window, GameObjects* gameObjects);

	bool handleInput(SDL_Event& e);
	void update(SDL_Event& e);
	void renderGameObjects();

	bool start();
	bool stop();

	Game(const Game& camera) = delete;
	Game& operator=(const Game&) = delete;
	Game(Game&&) = delete;
	Game& operator=(Game&&) = delete;
};