#pragma once
#include <SDL.h>

namespace util
{
	inline float getAmountOfTimePassedFromStartInSeconds()
	{
		float t = (float)SDL_GetTicks();
		t *= 0.001f;

		return t;
	}

	inline const float getTimeDelta()
	{
		return 1.0f / 100.0f;
	}

	inline const float getScreenWidth()
	{
		return 1152;
	}

	inline const float getScreenHeight()
	{
		return 768;
	}

	inline const int getTileDim()
	{
		return 64;
	}
}