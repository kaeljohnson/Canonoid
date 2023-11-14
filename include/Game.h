#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include "Renderer.h"
#include "GameObjects.h"
#include "Camera.h"

class Game 
{
private:
	bool running;

	Renderer* ptrWindow;
	Camera* ptrCamera;
	GameObjects* ptrGameObjects;

	Game();
	static Game* pInstance;

public:
	static Game* getInstance();

	void initialize(Renderer* window, Camera* camera, GameObjects* gameObjects);

	bool handleInput(SDL_Event& e);
	void update();

	bool start();
	bool stop();

	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	Game(Game&&) = delete;
	Game& operator=(Game&&) = delete;
};