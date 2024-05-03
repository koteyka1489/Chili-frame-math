#include "Camera.h"

void Camera::Update(MainWindow& wnd)
{
	MoveCamera(wnd);
}

Vec2 Camera::GetOffset()
{
	return offsetCenter + offsetMoveCamera;
}

void Camera::MoveCamera(MainWindow& wnd)
{
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		offsetMoveCamera = offsetMoveCamera + Vec2{ 0.0f, stepMoveCamera };
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		offsetMoveCamera = offsetMoveCamera + Vec2{ 0.0f, -stepMoveCamera };
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		offsetMoveCamera = offsetMoveCamera + Vec2{ stepMoveCamera, 0.0f };
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		offsetMoveCamera = offsetMoveCamera + Vec2{ -stepMoveCamera, 0.0f };
	}
}
