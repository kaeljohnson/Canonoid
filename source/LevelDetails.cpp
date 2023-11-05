#pragma once

#include <string>

#include "../include/LevelDetails.h"

LevelDetails::LevelDetails() : m_levelString(""), m_levelWidthInTiles(0), m_levelHeightInTiles(0), m_levelWidthInPixels(0),
							   m_levelHeightInPixels(0), m_tileWidthInPixels(0), m_tileHeightInPixels(0) {}

LevelDetails::LevelDetails(const std::string levelString, 
	                       const float levelWidthInTiles, 
	                       const float levelHeightInTiles, 
	                       const float levelWidthInPixels, 
	                       const float levelHeightInPixels, 
	                       const float tileWidthInPixels, 
	                       const float tileHeightInPixels,
						   const float playerStartingX,
	                       const float playerStartingY) 
					:  m_levelString(levelString), 
	                   m_levelWidthInTiles(levelWidthInTiles), 
	                   m_levelHeightInTiles(levelHeightInTiles), 
	                   m_levelWidthInPixels(levelWidthInPixels),
	                   m_levelHeightInPixels(levelHeightInPixels), 
	                   m_tileWidthInPixels(tileWidthInPixels), 
	                   m_tileHeightInPixels(tileHeightInPixels) {}
