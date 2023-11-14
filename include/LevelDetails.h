#pragma once

#include <string>

class LevelDetails
{
public:
	std::string m_levelString;

	int m_levelWidthInTiles;
	int m_levelHeightInTiles;

	int m_levelWidthInPixels;
	int m_levelHeightInPixels;

	int m_tileWidthInPixels;
	int m_tileHeightInPixels;

	LevelDetails();
	LevelDetails(const std::string levelString,
				 const int levelWidthInTiles,
				 const int levelHeightInTiles,
				 const int levelWidthInPixels,
				 const int levelHeightInPixels,
				 const int tileWidthInPixels,
				 const int tileHeightInPixels);
};