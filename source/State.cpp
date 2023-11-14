#pragma once

#include "../include/State.h"

State::State()
	: prevXPos(0), prevYPos(0), prevXVel(0), prevYVel(0), prevXAccel(0), prevYAccel(0),
	  currXPos(0), currYPos(0), currXVel(0), currYVel(0), currXAccel(0), currYAccel(0),
	  nextXPos(0), nextYPos(0), nextXVel(0), nextYVel(0), nextXAccel(0), nextYAccel(0),
	  mPhysOn(false)
{}

State::State(float startXPos, float startYPos, float startXVel, float startYVel, bool physOn)
	: prevXPos(startXPos), prevYPos(startYPos), prevXVel(startXVel), prevYVel(startYVel), prevXAccel(0), prevYAccel(0),
	  currXPos(startXPos), currYPos(startYPos), currXVel(startXVel), currYVel(startYVel), currXAccel(0), currYAccel(0),
	  nextXPos(startXPos), nextYPos(startYPos), nextXVel(startXVel), nextYVel(startYVel), nextXAccel(0), nextYAccel(0),
	  mPhysOn(physOn)
{}
