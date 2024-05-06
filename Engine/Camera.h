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
	Vec2 GetCenterCamera();
	float GetScaleCameraMod();
	float GetThetaRotation();

private:
	void MoveCamera(MainWindow& wnd);
	void ScaleCamera(MainWindow& wnd);
	void UpdateMousePos(MainWindow& wnd);
	void RotationCamera(MainWindow& wnd);
private:
	Vec2 offsetCenter{ Graphics::ScreenWidth / 2, Graphics::ScreenHeight / 2 };
	Vec2 offsetMoveCamera{ 0.f, 0.f };
	Vec2 mouseStartPos{ 0.f, 0.f };
	float stepMoveCamera = 5.0f;
	float scaleCameraMod = 1.0f;
	int mouseUpdateTicks = 0;
	int mouseUpdateTicksMax = 5;
	float ThetaRotation = 0.0f;

};

