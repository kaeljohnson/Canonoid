#pragma once
#include <SDL.h>

namespace util
{
	inline float getAmountOfTimePassedFromStartInSeconds()
	{
		float t = SDL_GetTicks();
		t *= 0.001f;

		return t;
	}

	inline const float getTimeDelta()
	{
		return 1.00 / 120.00f;
	}

	inline const int getScreenWidth()
	{
		// Must be multiple of 48
		return 1200;
	}

	inline const int getScreenHeight()
	{
		// Must be multiple of 48
		return 720;
	}

    
}