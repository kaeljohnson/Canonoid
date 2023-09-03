#pragma once
#include <SDL.h>

namespace util
{
	inline double getAmountOfTimePassedFromStartInSeconds()
	{
		double t = SDL_GetTicks();
		t *= 0.001f;

		return t;
	}

	inline const double getTimeDelta()
	{
		return 1.00 / 100.00f;
	}

	inline const int getScreenWidth()
	{
		// Must be multiple of 64
		return 1200;
	}

	inline const int getScreenHeight()
	{
		// Must be multiple of 64
		return 720;
	}
}

namespace gameHelpers
{
	inline const bool collision(Entity& rectOne, Entity& rectTwo)
	{
		float oneLeft = rectOne.state.getXPos();
		float oneRight = rectOne.state.getXPos() + rectOne.getCurrFrame().w;
		float twoLeft = rectTwo.state.getXPos();
		float twoRight = rectTwo.state.getXPos() + rectTwo.getCurrFrame().w;

		float oneTop = rectOne.state.getYPos();
		float oneBottom = rectOne.state.getYPos() - rectOne.getCurrFrame().h;
		float twoTop = rectTwo.state.getYPos();
		float twoBottom = rectTwo.state.getYPos() - rectTwo.getCurrFrame().h;

		/*
		std::cout << "One Left: " << oneLeft << "\n" <<
			"One Right: " << oneRight << "\n" <<
			"Two Left: " << twoLeft << "\n" <<
			"Two Right: " << twoRight << "\n" <<
			"One Top: " << oneTop << "\n" <<
			"One Bottom: " << oneBottom << "\n" <<
			"Two Top: " << twoTop << "\n" <<
			"Two Bottom: " << twoBottom << "\n";
		*/

		bool topBottomCollision = oneTop > twoBottom && oneBottom < twoTop;
		bool sidewaysCollision = oneRight >= twoLeft && oneLeft <= twoRight;
		
		if (topBottomCollision && sidewaysCollision)
		{
			return true;
		}
		return false;
	}
}