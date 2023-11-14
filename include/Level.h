#pragma once
#include <string>
#include <vector>
#include <unordered_map>

#include "Tile.h"
#include "Renderer.h"
#include "LevelDetails.h"

class Level 
{
private:
	LevelDetails m_levelDetails;

	float playerStartingX;
	float playerStartingY;

	Renderer* ptrWindow;

	std::vector<std::vector<Tile>> m_map;
	SDL_Texture* ptrFloorTexture;

public:

	Level(Renderer* window, std::unordered_map<std::string, SDL_Texture*>& levelTextures);

	const std::string& getMapString() const;
	const int getLevelWidth() const;
	const int getLevelHeight() const;
	const float getPlayerStartingX() const;
	const float getPlayerStartingY() const;
	const LevelDetails& getLevelDetails() const;
	const std::vector<std::vector<Tile>>& getMap() const;

	bool renderViewableArea(const float offsetX, const float offsetY, const float cameraWidth, const float cameraHeight, const float interpolation);

	bool loadMap();
};