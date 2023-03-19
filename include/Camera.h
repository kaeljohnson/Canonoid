#pragma once

// Singleton
class Camera
{
private:
	Camera();
	static Camera* static_instance;
public:
	inline static Camera* GetInstance() 
	{
		return static_instance = (static_instance != nullptr) ? static_instance : new Camera();
	}
};