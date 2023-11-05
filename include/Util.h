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
		return 1.0 / 100.0f;
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