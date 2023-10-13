#pragma once
#include <iostream>

class State
{
protected:
	float xPos;
	float yPos;
	float xVel;
	float yVel;
	float mPhysOn;

public:
	State();

	State(float startXPos, float startYPos, float startXVel, float startYVel, bool physOn);

	void setXPos(double newXPos);

	void setYPos(double newYPos);

	void setXVel(double newXVel);

	void setYVel(double newYVel);

    double getXPos();

	double getYPos();

	double getXVel();

	double getYVel();
};