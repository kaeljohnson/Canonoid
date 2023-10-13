#pragma once
#include <string>
#include <vector>
class Level 
{
private:
	std::string mapString;
	const int m_numTilesLevelWidth = 50;
	const int m_numTilesLevelHeight = 15;

	const int m_levelWidth = 3200;
	const int m_levelHeight = 960;
	const int m_tileWidth = 64;
	const int m_tileHeight = 64;

public:
	Level(std::string stringToMap);

	std::string getMapString();
	int getLevelWidth();
	int getLevelHeight();
	int getTileLevelWidth();
	int getTileLevelHeight();
};