#include "ScreenCoordinateTransformer_3D.h"

ScreenCoordinateTransformer_3D::ScreenCoordinateTransformer_3D()
	:
	xFactor((float)Graphics::ScreenWidth / 2.f),
	yFactor((float)Graphics::ScreenHeight / 2.f)
{}

Vec3& ScreenCoordinateTransformer_3D::Transform(Vec3 & v)
{
	float zFactor = 1 / v.z;
	v.x = (v.x * zFactor + 1.f) * xFactor;
	v.y = (-v.y * zFactor + 1.f) * yFactor;
	

	return v;
}
