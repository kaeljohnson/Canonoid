#include "../include/State.h"

State::State()
	: xPos(0), yPos(0), xVel(0), yVel(0), mPhysOn(false)
{

}

State::State(float startXPos, float startYPos, float startXVel, float startYVel, bool physOn)
	: xPos(startXPos), yPos(startYPos), xVel(startXVel), yVel(startYVel), mPhysOn(physOn)
{

}

void State::updateState(float newXPos, float newYPos, float newXVel, float newYVel, bool physOn)
{
	xPos = newXPos;
	yPos = newYPos;
	xVel = newXVel;
	yVel = newYVel;
	physOn = physOn;
}

double State::getXPos()
{
	return xPos;
}

double State::getPrevXPos()
{
	return prevXPos;
}

double State::getYPos()
{
	return yPos;
}

double State::getPrevYPos()
{
	return prevYPos;
}

double State::getXVel()
{
	return xVel;
}

double State::getPrevXVel()
{
	return prevXVel;
}

double State::getYVel()
{
	return yVel;
}

double State::getPrevYVel()
{
	return prevYVel;
}

void State::setXPos(double newXPos)
{
	prevXPos = xPos;
	xPos = newXPos;
}

void State::setYPos(double newYPos)
{
	prevYPos = yPos;
	yPos = newYPos;
}

void State::setXVel(double newXVel)
{
	prevXVel = xVel;
	xVel = newXVel;
}

void State::setYVel(double newYVel)
{
	prevYVel = yVel;
	yVel = newYVel;
}