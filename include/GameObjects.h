#pragma once

#include <SDL.h>
#include <vector>

#include "Player.h"
#include "Renderer.h"
#include "Camera.h"
#include "Level.h"
#include "PlayerConfig.h"
#include "Entity.h"

class GameObjects
{
private:
	Renderer& refWindow;
	Camera& refCamera;
	Level& refLevel;
	Player* m_ptrPlayer;

	std::vector<Entity*> collidableEntities;
	std::vector<Entity*> moveableEntities;

	float m_offsetX;
	float m_offsetY;

public:
	GameObjects(Renderer& window, Player* playerConfig, Camera& camera, Level& level);

	Player* getPlayer();

	void handleUserInput(SDL_Event& e);
	
	void updatePhysics();

	//void setNextPotentialStates();
	
	void moveObjects();
	void moveCamera();
	void clampCamera();

	void setOffsets();

	void checkCollisions();

	void interpolateObjectStates(float alpha);

	bool renderObjects(const float interpolation);

	bool cleanUp();
};