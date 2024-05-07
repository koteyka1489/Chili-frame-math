#include "Camera.h"

Camera::Camera(MouseInput& mInput, KeyboardInput& kInput)
	:
	mInput(mInput),
	kInput(kInput)
{}
void Camera::Update()
{
	UpdateMousePos();
	MoveCamera();
	ScaleCamera();
	RotationCamera();
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

void Camera::ScaleCamera()
{
	if (mInput.GetWheelUp())
	{
		scaleCameraMod *= 1.05f;
	}
	if (mInput.GetWheelDown())
	{
		scaleCameraMod /= 1.05f;
	}
}

void Camera::UpdateMousePos()
{
	if (mouseUpdateTicks >= mouseUpdateTicksMax)
	{
		mouseStartPos = mInput.GetMousePos();
		mouseUpdateTicks = 0;
	}
	else
	{
		mouseUpdateTicks++;
	}

}

void Camera::RotationCamera()
{
	if (kInput.EIsPresses())
	{
		ThetaRotation += 0.1f;
	}
	if (kInput.QIsPressed())
	{
		ThetaRotation -= 0.1;
	}
}
