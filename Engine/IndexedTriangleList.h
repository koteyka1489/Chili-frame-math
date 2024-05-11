#pragma once
#include <vector>
#include "Vec3.h"
#include "Vec2.h"

struct  IndexedTriangleList
{
	std::vector<Vec3> vertices;
	std::vector<size_t> indexes;
};