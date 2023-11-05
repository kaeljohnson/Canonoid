#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <vector>

#include "Player.h"
#include "WindowRenderer.h"
#include "Camera.h"
#include "Level.h"
#include "PlayerConfig.h"

class GameObjects
{
private:
	WindowRenderer& refWindow;
	Camera& refCamera;
	Level& refLevel;
	Player* m_ptrPlayer;

	std::vector<Entity*> collidableEntities;
	std::vector<Entity*> moveableEntities;

	float m_offsetX;
	float m_offsetY;

public:
	GameObjects(WindowRenderer& window, PlayerConfig& playerConfig, Camera& camera, Level& level);

	Player* getPlayer();

	void handleUserInput(SDL_Event& e);

	void moveObjects();
	void moveCamera();
	void clampCamera();

	void setOffsets();
	const float getCurrentOffsetX() const;
	const float getCurrentOffsetY() const;

	void checkCollisions();

	void interpolateObjectStates(float alpha);

	bool renderObjects(const float interpolation);

	bool cleanUp();
};