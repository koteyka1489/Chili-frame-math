#include "Camera.h"

Camera::Camera(MouseInput& mInput)
	:
	mInput(mInput)
{}
void Camera::Update()
{
	UpdateMousePos(wnd);
	MoveCamera(wnd);
	ScaleCamera(wnd);
	RotationCamera(wnd);
}



Vec2 Camera::GetOffset()
{
	return offsetCenter  + offsetMoveCamera;
}

Vec2 Camera::GetCenterCamera()
{
	Vec2 temp{0.f, 0.f};
	temp += GetOffset();
	return temp;
}

float Camera::GetScaleCameraMod()
{
	return scaleCameraMod;
}

float Camera::GetThetaRotation()
{
	return ThetaRotation;
}

void Camera::MoveCamera()
{
	offsetMoveCamera = Vec2{ 0.f, 0.f };
	Vec2 temp = { 0.f, 0.f };

	if (mInput.GetLeftIsPressed())
	{
		Vec2 mousePressPoint = mInput.GetMousePos();
		Vec2Dir mouseVecDir(mousePressPoint, mouseStartPos);
		mouseVecDir = mouseVecDir.Normalize();
		temp += mouseVecDir * 1.5f;
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

void Camera::UpdateMousePos(MainWindow& wnd)
{
	if (mouseUpdateTicks >= mouseUpdateTicksMax)
	{
		mouseStartPos = Vec2{ (float)wnd.mouse.GetPosX(), (float)wnd.mouse.GetPosY() };
		mouseUpdateTicks = 0;
	}
	else
	{
		mouseUpdateTicks++;
	}

}

void Camera::RotationCamera(MainWindow& wnd)
{
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		ThetaRotation += 0.1f;
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		ThetaRotation -= 0.1;
	}
}
