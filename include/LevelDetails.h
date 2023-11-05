#pragma once

#include <string>

class LevelDetails
{
public:
	std::string m_levelString;

	float m_levelWidthInTiles;
	float m_levelHeightInTiles;

	float m_levelWidthInPixels;
	float m_levelHeightInPixels;

	float m_tileWidthInPixels;
	float m_tileHeightInPixels;

	LevelDetails();
	LevelDetails(const std::string levelString,
				 const float levelWidthInTiles,
				 const float levelHeightInTiles,
				 const float levelWidthInPixels,
				 const float levelHeightInPixels,
				 const float tileWidthInPixels,
				 const float tileHeightInPixels,
				 const float playerStartingX,
				 const float playerStartingY);
};