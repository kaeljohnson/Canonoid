#pragma once

#include <vector>

#include "Tile.h"
#include "Level.h"

class Camera
{
private:
	// Not really sure how to handle the camera moving around the level? For now just have a pointer to the level in here.
	Level* m_level;

	float m_x;
	float m_y;
	int m_w;
	int m_h;

	Camera();
	static Camera* pInstance;

public:
	static Camera* getInstance();

	Camera(const Camera& camera) = delete;
	Camera& operator=(const Camera&) = delete;
	Camera(Camera&&) = delete;
	Camera& operator=(Camera&&) = delete;

	void move(float x, float y);
	void clamp(float& offsetX, float& offsetY);

	float getXValue();
	float getYValue();
	void setCameraValues(float x, float y, int h, int w, Level* level);


};