#pragma once

#include "../include/State.h"

State::State()
	: xPos(0), yPos(0), xVel(0), yVel(0), mPhysOn(false)
{

}

State::State(float startXPos, float startYPos, float startXVel, float startYVel, bool physOn)
	: xPos(startXPos), yPos(startYPos), xVel(startXVel), yVel(startYVel), mPhysOn(physOn)
{

}

double State::getXPos()
{
	return xPos;
}

double State::getYPos()
{
	return yPos;
}

double State::getXVel()
{
	return xVel;
}

double State::getYVel()
{
	return yVel;
}

void State::setXPos(double newXPos)
{
	xPos = newXPos;
}

void State::setYPos(double newYPos)
{
	yPos = newYPos;
}

void State::setXVel(double newXVel)
{
	xVel = newXVel;
}

void State::setYVel(double newYVel)
{
	yVel = newYVel;
}