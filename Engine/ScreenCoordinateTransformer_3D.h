#pragma once
#include "Graphics.h"
#include "Vec3.h"

class ScreenCoordinateTransformer_3D
{
public:
	ScreenCoordinateTransformer_3D();
	Vec3& Transform(Vec3& v);

private:
	float xFactor;
	float yFactor;
	
};

