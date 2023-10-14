#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <vector>

#include "Player.h"
#include "WindowRenderer.h"
#include "Tile.h"

class GameObjects
{
private:
	Player* m_player;
	SDL_Texture* m_floorSprite;
	WindowRenderer* m_window;
	std::vector<std::vector<Tile>> m_levelMap;
	Level* m_level;

	float m_offsetX;
	float m_offsetY;

public:
	GameObjects(WindowRenderer* window);

	Player* getPlayer();
	std::vector<std::vector<Tile>>& getLevelMap();

	void handleUserInput(SDL_Event& e);
	void moveObjects();
	void moveCamera();
	void clampCamera();

	void setOffsets();
	bool loadMap();
	bool renderViewableArea();
	bool renderObjects();
	bool renderPlayer();
	bool cleanUp();
};