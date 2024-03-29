#pragma once

#include <string>

#include "../include/LevelDetails.h"

LevelDetails::LevelDetails() : m_levelString(""), m_levelWidthInTiles(0), m_levelHeightInTiles(0), m_levelWidthInPixels(0),
							   m_levelHeightInPixels(0), m_tileWidthInPixels(0), m_tileHeightInPixels(0) {}

LevelDetails::LevelDetails(const std::string levelString, 
	                       const int levelWidthInTiles, 
	                       const int levelHeightInTiles, 
	                       const int levelWidthInPixels, 
	                       const int levelHeightInPixels, 
	                       const int tileWidthInPixels, 
	                       const int tileHeightInPixels) 
					:  m_levelString(levelString), 
	                   m_levelWidthInTiles(levelWidthInTiles), 
	                   m_levelHeightInTiles(levelHeightInTiles), 
	                   m_levelWidthInPixels(levelWidthInPixels),
	                   m_levelHeightInPixels(levelHeightInPixels), 
	                   m_tileWidthInPixels(tileWidthInPixels), 
	                   m_tileHeightInPixels(tileHeightInPixels) {}
