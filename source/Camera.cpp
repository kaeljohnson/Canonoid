#include "../include/Camera.h"

Camera::Camera() : m_x(0), m_y(0), m_h(0), m_w(0), m_levelWidth(0), m_levelHeight(0), m_level(nullptr), m_levelMap(nullptr)
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
	if (offsetX + util::getScreenWidth() > m_levelWidth) { offsetX = m_levelWidth - util::getScreenWidth(); }
	if (offsetY + util::getScreenHeight() > m_levelHeight) { offsetY = m_levelHeight - util::getScreenHeight(); }
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

void Camera::setCameraValues(float x, float y, int h, int w, Level* level, std::vector<std::vector<Tile>>* levelMap)
{
	m_x = x;
	m_y = y;
	m_h = h;
	m_w = w;

	m_levelMap = levelMap;
	m_levelWidth = level->getLevelWidth();
	m_levelHeight = level->getLevelHeight();
}

float Camera::getXValue()
{
	return m_x;
}

float Camera::getYValue()
{
	return m_y;
}
