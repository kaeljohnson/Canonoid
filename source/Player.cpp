#include "../include/Player.h"
#include "../include/Util.h"

#include <stdio.h>

Player::Player(int x, int y, SDL_Texture* playerSprite)
	: Entity(x, y, playerSprite)
{
	size_t frameIdx = 0;
	size_t xStart = 0;


	// After physics is implemented this will be an entire animation sprite sheet, not just a single player rect.
	SDL_Rect& playerRect = getCurrFrame();
	playerRect.x = 0;
	playerRect.y = 0;
	playerRect.w = 48 * 2;
	playerRect.h = 48 * 2;


	setCurrParentFrame(playerRect);
}