#include "Camera.h"

void Camera::Update(MainWindow& wnd)
{
	MoveCamera(wnd);
	ScaleCamera(wnd);
}

Vec2 Camera::GetOffset()
{
	return offsetCenter  + offsetMoveCamera;
}

float Camera::GetScaleCameraMod()
{
	return scaleCameraMod;
}

void Camera::MoveCamera(MainWindow& wnd)
{
	offsetMoveCamera = Vec2{ 0.f, 0.f };
	Vec2 temp = { 0.f, 0.f };
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		temp +=  Vec2{ 0.0f, stepMoveCamera };
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		temp += Vec2{ 0.0f, -stepMoveCamera };
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		temp +=  Vec2{ stepMoveCamera, 0.0f };
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		temp +=  Vec2{ -stepMoveCamera, 0.0f };
	}

	offsetMoveCamera += temp;
}

void Camera::ScaleCamera(MainWindow& wnd)
{
	const auto e = wnd.mouse.Read();

	if (e.GetType() == Mouse::Event::Type::WheelUp)
	{
		scaleCameraMod *= 1.05f;
	}
	if (e.GetType() == Mouse::Event::Type::WheelDown)
	{
		scaleCameraMod /= 1.05f;
	}
}
