#pragma once
#include <string>
class Level 
{
private:
	std::string mapString;
	int m_levelWidth = 50;
	int m_levelHeight = 15;

public:
	Level(std::string stringToMap);

	std::string getMapString();
	int getLevelWidth();
	int getLevelHeight();
};