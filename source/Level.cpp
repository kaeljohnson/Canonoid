#include "../include/Level.h"

Level::Level(std::string stringToMap)
	: mapString(stringToMap)
{

}

std::string Level::getMapString()
{
	return mapString;
}

int Level::getLevelWidth()
{
	return m_levelWidth;
}

int Level::getLevelHeight()
{
	return m_levelHeight;
}