#pragma once

class Camera
{
private:

	float m_x;
	float m_y;
	float m_w;
	float m_h;

	float valLevelWidth;
	float valLevelHeight;
	
public:
	Camera();
	Camera(float x, float y, float w, float h, float levelWidth, float levelHeight);

	Camera(const Camera& camera) = delete;
	Camera& operator=(const Camera&) = delete;
	Camera(Camera&&) = delete;
	Camera& operator=(Camera&&) = delete;

	void move(float x, float y);
	void clamp(float& offsetX, float& offsetY);

	const float getXValue() const;
	const float getYValue() const;
	const float getWidth() const;
	const float getHeight() const;
};