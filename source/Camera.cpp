#pragma once

#include "../include/Camera.h"
#include "../include/Util.h"

Camera::Camera() : m_x(0), m_y(0), m_h(0), m_w(0), valLevelWidth(0), valLevelHeight(0) {}

Camera::Camera(float x, float y, const float w, const float h, const int levelWidth, const int levelHeight)
	: m_x(x), m_y(y), m_w(w), m_h(h), valLevelWidth(levelWidth), valLevelHeight(levelHeight) {}

void Camera::move(float x, float y)
{
	m_x = x;
	m_y = y;
}

void Camera::clamp(float& offsetX, float& offsetY)
{
	if (offsetX < 0) { offsetX = 0; }
	if (offsetY < 0) { offsetY = 0; }
	if (offsetX + util::getScreenWidth() > valLevelWidth) { offsetX = valLevelWidth - util::getScreenWidth(); }
	if (offsetY + util::getScreenHeight() > valLevelHeight) { offsetY = valLevelHeight - util::getScreenHeight(); }
}

const float Camera::getXValue() const
{
	return m_x;
}

const float Camera::getYValue() const
{
	return m_y;
}

const float Camera::getWidth() const
{
	return m_w;
}

const float Camera::getHeight() const
{
	return m_h;
}
