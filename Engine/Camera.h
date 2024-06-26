#pragma once
#include "Vec2.h"
#include "Graphics.h"
#include "MainWindow.h"
#include "Input.h"
#include "XMath.h"

class Camera
{
public:
	Camera(MouseInput& mInput, KeyboardInput& kInput);
	void Update();
	Vec2 GetOffset();
	Vec2 GetCenterCamera();
	float GetScaleCameraMod();
	float GetThetaRotation();

private:
	void MoveCamera();
	void ScaleCamera();
	void RotationCamera();
private:
	MouseInput& mInput;
	KeyboardInput& kInput;
	Vec2 offsetCenter{ Graphics::ScreenWidth / 2, Graphics::ScreenHeight / 2 };
	Vec2 offsetMoveCamera{ 0.f, 0.f };
	Vec2 mouseStartPos{ Graphics::ScreenWidth / 2, Graphics::ScreenHeight / 2 };
	float stepMoveCamera = 5.0f;
	float scaleCameraMod = 1.0f;
	int mouseUpdateTicks = 0;
	int mouseUpdateTicksMax = 10;
	float ThetaRotation = 0.0f;

};

