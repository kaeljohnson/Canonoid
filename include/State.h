#pragma once

class State
{
public:
	float prevXPos;
	float prevYPos;
	float prevXVel;
	float prevYVel;
	float prevXAccel;
	float prevYAccel;

	float currXPos;
	float currYPos;
	float currXVel;
	float currYVel;
	float currXAccel;
	float currYAccel;

	float nextXPos;
	float nextYPos;
	float nextXVel;
	float nextYVel;
	float nextXAccel;
	float nextYAccel;

	float mPhysOn;

	State();

	State(float startXPos, float startYPos, float startXVel, float startYVel, bool physOn);
};