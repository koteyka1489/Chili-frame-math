#include "UpdateScrenCoordinate.h"




UpdateScrenCoordinate::UpdateScrenCoordinate(Camera& camera_in)
	:
	camera(camera_in)
{}

UpdateScrenCoordinate UpdateScrenCoordinate::operator=(UpdateScrenCoordinate& rhs)
{
	shapesUPS = rhs.shapesUPS;
	return *this;
}

void UpdateScrenCoordinate::Init(std::vector<Shape> shapesIN)
{
	shapesUPS = shapesIN;
}

void UpdateScrenCoordinate::Update()
{
	Matrix3 rotationMatrix = rotationMatrix.RotateMatrix3(camera.GetThetaRotation());
	Matrix3 scaleMatrix = scaleMatrix.ScaleMatrix3(camera.GetScaleCameraMod());
	Matrix3 translationMatrix = translationMatrix.TranslateMatrix3(camera.GetOffset());
	Matrix3 modelMatrix = translationMatrix * scaleMatrix * rotationMatrix;
	for (auto& s : shapesUPS)
	{
		s.SetModelMatrix(modelMatrix);
	}

	//for (auto& s : shapesUPS)
	//{
	//	s.SetRotation(camera.GetThetaRotation(), Vec2{ 0.f, 0.f });
	//	s.SetPointsScale(camera.GetScaleCameraMod());
	//	s.SetPointsOfset(camera.GetOffset());
	//}
}

std::vector<Shape>* UpdateScrenCoordinate::GetShapes()
{
	return &shapesUPS;
}
