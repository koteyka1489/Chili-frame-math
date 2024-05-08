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


	for (auto& s : shapesUPS)
	{
		s.SetPointsScale(camera.GetScaleCameraMod());
		s.SetPointsOfset(camera.GetOffset());
	}
}

std::vector<Shape>* UpdateScrenCoordinate::GetShapes()
{
	return &shapesUPS;
}
