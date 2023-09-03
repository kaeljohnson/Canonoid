#pragma once
#include <iostream>

class State
{
protected:
	float prevXPos;
	float prevYPos;
	float xPos;
	float yPos;
	float prevXVel;
	float prevYVel;
	float xVel;
	float yVel;
	float mPhysOn;

public:
	State();

	State(float startXPos, float startYPos, float startXVel, float startYVel, bool physOn);

	void updateState(float newXPos, float newYPos, float newXVel, float newYVel, bool physOn);

	void setXPos(double newXPos);

	void setYPos(double newYPos);

	void setXVel(double newXVel);

	void setYVel(double newYVel);

    double getXPos();

	double getPrevXPos();

	double getYPos();

	double getPrevYPos();

	double getXVel();

	double getPrevXVel();

	double getYVel();

	double getPrevYVel();
};