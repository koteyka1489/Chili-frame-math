#pragma once
#include "Vec2.h"
#include "Graphics.h"
#include "MainWindow.h"

class Camera
{
public:
	Camera() = default;
	void Update(MainWindow& wnd);
	Vec2 GetOffset();
	float GetScaleCameraMod();

private:
	void MoveCamera(MainWindow& wnd);
	void ScaleCamera(MainWindow& wnd);
private:
	Vec2 offsetCenter{ Graphics::ScreenWidth / 2, Graphics::ScreenHeight / 2 };
	Vec2 offsetMoveCamera{ 0, 0 };
	float stepMoveCamera = 5.0f;
	float scaleCameraMod = 1.0f;

};

