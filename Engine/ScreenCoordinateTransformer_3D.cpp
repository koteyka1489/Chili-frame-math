#include "ScreenCoordinateTransformer_3D.h"

ScreenCoordinateTransformer_3D::ScreenCoordinateTransformer_3D()
	:
	xFactor((float)Graphics::ScreenWidth / 2.f),
	yFactor((float)Graphics::ScreenHeight / 2.f)
{}

Vec3& ScreenCoordinateTransformer_3D::Transform(Vec3 & v)
{
	v.x = (v.x + 1.f) * xFactor;
	v.y = (-v.y + 1.f) * yFactor;

	return v;
}
