#include "Camera.h"

Camera::Camera(MouseInput& mInput, KeyboardInput& kInput)
	:
	mInput(mInput),
	kInput(kInput)
{}

void Camera::Update()
{
	
	MoveCamera();
	ScaleCamera();
	//RotationCamera();
	RotationCameraXYZ();
}



Vec2 Camera::GetOffset()
{
	return (offsetCenter  + offsetMoveCamera);
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

float Camera::GetThetaRotation_X()
{
	return thetaRotationX;
}

float Camera::GetThetaRotation_Y()
{
	return thetaRotationY;
}

float Camera::GetThetaRotation_Z()
{
	return thetaRotationZ;
}

Vec3 Camera::GetCameraVec()
{
	return cameraVec;
}

void Camera::MoveCamera()
{
	if (kInput.WIsPressed())
	{
		cameraVec.z += cameraSpeed;
	}
	if (kInput.AIsPressed())
	{
		cameraVec.x -= cameraSpeed;
	}
	if (kInput.SIsPressed())
	{
		cameraVec.z -= cameraSpeed;
	}
	if (kInput.DIsPressed())
	{
		cameraVec.x += cameraSpeed;
	}

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



void Camera::RotationCamera()
{
	if (kInput.EIsPresses())
	{
		ThetaRotation +=  0.01 * PI;
	}
	if (kInput.QIsPressed())
	{
		ThetaRotation -= 0.01 * PI;
	}
}

void Camera::RotationCameraXYZ()
{
	if (kInput.QIsPressed())
	{
		if (thetaRotationZ >= 2.f * PI)
		{
			thetaRotationZ = 0.f;
			thetaRotationZ += 0.01 * PI;
		}
		else
		{
			thetaRotationZ += 0.01 * PI;
		}
	}
	if (kInput.EIsPresses())
	{
		if (thetaRotationZ <= -2.f * PI)
		{
			thetaRotationZ = 0.f;
			thetaRotationZ -= 0.01 * PI;
		}
		else
		{
			thetaRotationZ -= 0.01 * PI;
		}
	}
	if (kInput.UpIsPressed())
	{
		if (thetaRotationX >= 2.f * PI)
		{
			thetaRotationX = 0.f;
			thetaRotationX += 0.01 * PI;
		}
		else
		{
			thetaRotationX += 0.01 * PI;
		}
	}
	if (kInput.DownIsPressed())
	{
		if (thetaRotationX <= -2.f * PI)
		{
			thetaRotationX = 0.f;
			thetaRotationX -= 0.01 * PI;
		}
		else
		{
			thetaRotationX -= 0.01 * PI;
		}
	}
	if (kInput.LefttIsPressed())
	{
		if (thetaRotationY >= 2.f * PI)
		{
			thetaRotationY = 0.f;
			thetaRotationY += 0.01 * PI;
		}
		else
		{
			thetaRotationY += 0.01 * PI;
		}
	}
	if (kInput.RightIsPressed())
	{
		if (thetaRotationY <= -2.f * PI)
		{
			thetaRotationY = 0.f;
			thetaRotationY -= 0.01 * PI;
		}
		else
		{
			thetaRotationY -= 0.01 * PI;
		}
	}

}
