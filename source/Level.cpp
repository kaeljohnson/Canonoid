#include "../include/Level.h"
#include "../include/Textures.h"

Level::Level(std::string stringToMap)
	: mapString(stringToMap)
{

}

std::string Level::getMapString()
{
	return mapString;
}

int Level::getTileLevelWidth()
{
	return m_numTilesLevelWidth;
}

int Level::getTileLevelHeight()
{
	return m_numTilesLevelHeight;
}

int Level::getLevelWidth()
{
	return m_levelWidth;
}

int Level::getLevelHeight()
{
	return m_levelHeight;
}