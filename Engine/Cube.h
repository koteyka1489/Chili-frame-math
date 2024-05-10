#pragma once
#include <vector>
#include "Vec3.h"
#include "IndexedLineList.h"

class Cube
{
public:
	Cube(float size);

	IndexedLineList GetLines();

private:
	std::vector<Vec3> vertices;
};

