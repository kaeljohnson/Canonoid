#pragma once

#include <string>

#include "LevelDetails.h"

// Need to come up with better level building interface.

namespace levels
{
	// To-do: Level builder class which takes in a string and builds level accordingly.
	// Player start should be its own character in the string. Then set that as the players starting coordinates.

	inline void getPlayground(LevelDetails& levelDetails)
	{
		std::string levelString;
		 
		levelString += "---g----------------------------------------------"; // 1
		levelString += "--------------------------------------------------"; // 2
		levelString += "g-g--g-g------------------------------------------"; // 3
		levelString += "ggg-g---------------------------------------------"; // 4
		levelString += "--------------------------------------------------"; // 5
		levelString += "---------------------g----g--g-g------------------"; // 6
		levelString += "--------------------------------------------------"; // 7
		levelString += "--------------------------------------------------"; // 8
		levelString += "---------------------------------------ggggggggggg"; // 9
		levelString += "--------------------g------------------g----------"; // 10
		levelString += "------------g--g-g---------------------g----------"; // 11
		levelString += "ggggggg-gggggggggggggggg-g-------------g----------"; // 12
		levelString += "-----------------------g-ggg----gggggggg----------"; // 13
		levelString += "-----------------------g-----ggg------------------"; // 14
		levelString += "-----------------------ggggggg--------------------"; // 15

		levelDetails.m_levelString = levelString;

		levelDetails.m_levelWidthInTiles = 50;
		levelDetails.m_levelHeightInTiles = 15;

		levelDetails.m_levelWidthInPixels = 3200;
		levelDetails.m_levelHeightInPixels = 960;

		levelDetails.m_tileWidthInPixels = 64;
		levelDetails.m_tileHeightInPixels = 64;
	}

	inline void getBigPlayground(LevelDetails& levelDetails)
	{
		std::string levelString;
		              
		levelString += "---g------------------------------------------------------------------------------------------------"; // 1
		levelString += "----------------------------------------------------------------------------------------------------"; // 2
		levelString += "g-g--g-g--------------------------------------------------------------------------------------------"; // 3
		levelString += "ggg-g------------------------------------------------------------------------------------g----------"; // 4
		levelString += "----------------------------------------------------------------------------------------g-g---------"; // 5
		levelString += "---------------------g----g--g-g---------------------------------------------------------g----------"; // 6
		levelString += "----------------------------------------------------------------------------------------------------"; // 7
		levelString += "-----------------------------------------------------------------------------------------gggg-------"; // 8
		levelString += "---------------------------------------ggggggggggg-----------------------------------g--------------"; // 9
		levelString += "--------------------g------------------g------------------------------------------------------------"; // 10
		levelString += "------------g--g-g---------------------g------------------------------------gggg----------------p---"; // 11
		levelString += "ggggggg-gggggggggggggggg-g-------------g------------------------------------------------------------"; // 12
		levelString += "-----------------------g-ggg----gggggggg-----------------------g-g-----------------ggg--------------"; // 13
		levelString += "-----------------------g-----ggg-------------------------------g-g----------------------------------"; // 14
		levelString += "-----------------------ggggggg--------------------------------g---g---------------------------------"; // 15
		levelString += "--------------------------------gggggggg---------------------g-----g---------------------gg---------"; // 16
		levelString += "-----------------------g-----ggg-----------------------------g-----g-------------------------------g"; // 17
		levelString += "-----------------------ggggggg--------------------------------ggggg-------------------------------gg"; // 18

		// Level Creator should be able to just modify map string and player start. Everything else below should be intuited.

		levelDetails.m_levelString = levelString;

		levelDetails.m_levelWidthInTiles = 100;
		levelDetails.m_levelHeightInTiles = 18;

		levelDetails.m_levelWidthInPixels = 6400;
		levelDetails.m_levelHeightInPixels = 1152;

		// Eventually should be able to have any size tile -> dependent on the texture. i.e. Tile class should be in charge of its own size.

		levelDetails.m_tileWidthInPixels = 64;
		levelDetails.m_tileHeightInPixels = 64;
	}
}

inline void getLevel1(LevelDetails& levelDetails)
{
	std::string levelString;

	levelString += "--------------------------------------------------"; // 1
	levelString += "--------------------------------------------------"; // 2
	levelString += "--------------------------------------------------"; // 3
	levelString += "--------------------------------------------------"; // 4
	levelString += "--------------------------------------------------"; // 5
	levelString += "---------------------g----g--g-g------------------"; // 6
	levelString += "--------------------------------------------------"; // 7
	levelString += "--------------------------------------------------"; // 8
	levelString += "---------------------------------------ggggggggggg"; // 9
	levelString += "--------------------g------------------g----------"; // 10
	levelString += "-p----------g--g-g---------------------g----------"; // 11
	levelString += "ggggggg-gggggggggggggggg-g-------------g----------"; // 12
	levelString += "-----------------------g-ggg----gggggggg----------"; // 13
	levelString += "-----------------------g-----ggg------------------"; // 14
	levelString += "-----------------------ggggggg--------------------"; // 15

	levelDetails.m_levelString = levelString;

	levelDetails.m_levelWidthInTiles = 50;
	levelDetails.m_levelHeightInTiles = 15;

	levelDetails.m_levelWidthInPixels = 3200;
	levelDetails.m_levelHeightInPixels = 960;

	levelDetails.m_tileWidthInPixels = 64;
	levelDetails.m_tileHeightInPixels = 64;
}