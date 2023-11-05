#pragma once

class State
{
protected:
	float prevXPos;
	float prevYPos;
	float prevXVel;
	float prevYVel;

	float xPos;
	float yPos;
	float xVel;
	float yVel;
	float mPhysOn;

public:
	State();

	State(float startXPos, float startYPos, float startXVel, float startYVel, bool physOn);

	void setXPos(float newXPos);

	void setYPos(float newYPos);

	void setXVel(float newXVel);

	void setYVel(float newYVel);

	void setPrevXPos(float newXPos);

	void setPrevYPos(float newYPos);

	void setPrevXVel(float newXVel);

	void setPrevYVel(float newYVel);

	const float getPrevXPos() const;

	const float getPrevYPos() const;

	const float getPrevXVel() const;

	const float getPrevYVel() const;

    const float getXPos() const;

	const float getYPos() const;

	const float getXVel() const;

	const float getYVel() const;
};