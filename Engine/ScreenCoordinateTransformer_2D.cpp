#include "ScreenCoordinateTransformer_2D.h"




ScreenCoordinateTransformer_2D::ScreenCoordinateTransformer_2D(Camera& camera_in)
	:
	camera(camera_in)
{}

ScreenCoordinateTransformer_2D ScreenCoordinateTransformer_2D::operator=(ScreenCoordinateTransformer_2D& rhs)
{
	shapesUPS = rhs.shapesUPS;
	return *this;
}

void ScreenCoordinateTransformer_2D::Init(std::vector<Shape> shapesIN)
{
	shapesUPS = shapesIN;
}

void ScreenCoordinateTransformer_2D::Update()
{
	/*Matrix3 rotationMatrix = rotationMatrix.RotateMatrix3(camera.GetThetaRotation());
	Matrix3 scaleMatrix = scaleMatrix.ScaleMatrix3(camera.GetScaleCameraMod());
	Matrix3 translationMatrix = translationMatrix.TranslateMatrix3(camera.GetOffset());
	Matrix3 modelMatrix = modelMatrix.GetModelMarixTRS(rotationMatrix, scaleMatrix,  translationMatrix);
	for (auto& s : shapesUPS)
	{
		s.SetModelMatrix(modelMatrix);
	}*/

	//for (auto& s : shapesUPS)
	//{
	//	s.SetRotation(camera.GetThetaRotation(), Vec2{ 0.f, 0.f });
	//	s.SetPointsScale(camera.GetScaleCameraMod());
	//	s.SetPointsOfset(camera.GetOffset());
	//}
}

std::vector<Shape>* ScreenCoordinateTransformer_2D::GetShapes()
{
	return &shapesUPS;
}
