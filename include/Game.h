#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

#include "WindowRenderer.h"
#include "GameObjects.h"
#include "Camera.h"

class Game 
{
private:
	bool running;

	WindowRenderer* ptrWindow;
	Camera* ptrCamera;
	GameObjects* ptrGameObjects;

	Game();
	static Game* pInstance;

public:
	static Game* getInstance();

	void initialize(WindowRenderer* window, Camera* camera, GameObjects* gameObjects);

	bool handleInput(SDL_Event& e);
	void update(SDL_Event& e);

	bool start();
	bool stop();

	Game(const Game& camera) = delete;
	Game& operator=(const Game&) = delete;
	Game(Game&&) = delete;
	Game& operator=(Game&&) = delete;
};