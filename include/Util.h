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
		return 1152;
	}

	inline const int getScreenHeight()
	{
		// Must be multiple of 64
		return 768;
	}
}

