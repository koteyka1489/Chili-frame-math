#pragma once
#include <vector>
#include "Vec3.h"
#include "IndexedLineList.h"
#include "IndexedTriangleList.h"

class Cube
{
public:
	Cube(float size);

	IndexedLineList GetLines();
	IndexedTriangleList GetTriangles();

private:
	std::vector<Vec3> vertices;
};

