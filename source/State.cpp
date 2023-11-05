#pragma once

#include "../include/State.h"

State::State()
	: prevXPos(0), prevYPos(0), prevXVel(0), prevYVel(0), xPos(0), yPos(0), xVel(0), yVel(0), mPhysOn(false)
{}

State::State(float startXPos, float startYPos, float startXVel, float startYVel, bool physOn)
	: xPos(startXPos), yPos(startYPos), xVel(startXVel), yVel(startYVel), prevXPos(startXPos), 
	  prevYPos(startYPos), prevXVel(startXVel), prevYVel(startYVel), mPhysOn(physOn)
{}

const float State::getXPos() const
{
	return xPos;
}

const float State::getYPos() const
{
	return yPos;
}

const float State::getXVel() const
{
	return xVel;
}

const float State::getYVel() const
{
	return yVel;
}

void State::setPrevXPos(float oldXPos)
{
	prevXPos = oldXPos;
}

void State::setPrevYPos(float oldYPos)
{
	prevYPos = oldYPos;
}

void State::setPrevXVel(float oldXVel)
{
	prevXVel = oldXVel;
}

void State::setPrevYVel(float oldYVel)
{
	prevYVel = oldYVel;
}

const float State::getPrevXPos() const
{
	return prevXPos;
}

const float State::getPrevYPos() const
{
	return prevYPos;
}

const float State::getPrevXVel() const
{
	return prevXVel;
}

const float State::getPrevYVel() const
{
	return prevYVel;
}

void State::setXPos(float newXPos)
{
	xPos = newXPos;
}

void State::setYPos(float newYPos)
{
	yPos = newYPos;
}

void State::setXVel(float newXVel)
{
	xVel = newXVel;
}

void State::setYVel(float newYVel)
{
	yVel = newYVel;
}