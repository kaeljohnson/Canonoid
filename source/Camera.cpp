#pragma once

#include "../include/Camera.h"
#include "../include/Util.h"

Camera::Camera() : m_x(0), m_y(0), m_h(0), m_w(0), m_level(nullptr)
{

}

void Camera::move(float x, float y)
{
	m_x = x;
	m_y = y;
}

void Camera::clamp(float& offsetX, float& offsetY)
{
	if (offsetX < 0) { offsetX = 0; }
	if (offsetY < 0) { offsetY = 0; }
	if (offsetX + util::getScreenWidth() > m_level->getLevelWidth()) { offsetX = m_level->getLevelWidth() - util::getScreenWidth(); }
	if (offsetY + util::getScreenHeight() > m_level->getLevelHeight()) { offsetY = m_level->getLevelHeight() - util::getScreenHeight(); }
}

Camera* Camera::getInstance()
{
	if (pInstance == nullptr)
	{
		pInstance = new Camera();

		return pInstance;
	}
	else
	{
		return pInstance;
	}
}

void Camera::setCameraValues(float x, float y, int h, int w, Level* level)
{
	m_x = x;
	m_y = y;
	m_h = h;
	m_w = w;

	m_level = level;
}

float Camera::getXValue()
{
	return m_x;
}

float Camera::getYValue()
{
	return m_y;
}
