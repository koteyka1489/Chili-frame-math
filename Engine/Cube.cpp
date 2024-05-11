#include "Cube.h"

Cube::Cube(float size)
{
	float side = size / 2.f;
	vertices.emplace_back( -side, -side,  -side);
	vertices.emplace_back(  side, -side,  -side);
	vertices.emplace_back( -side,  side,  -side);
	vertices.emplace_back(  side,  side,  -side);
	vertices.emplace_back( -side, -side,   side);
	vertices.emplace_back(  side, -side,   side);
	vertices.emplace_back( -side,  side,   side);
	vertices.emplace_back(  side,  side,   side);


}

IndexedLineList Cube::GetLines()
{
	return {
		vertices, {
			0,1, 1,3, 3,2, 2,0, 
			0,4, 1,5, 3,7, 2,6,
			4,5, 5,7, 7,6, 6,4
		}
	};
}

IndexedTriangleList Cube::GetTriangles()
{
	return {
		vertices, {
			0,2,1, 2,3,1,
			1,3,5, 3,7,5,
			2,6,3, 3,6,7,
			4,5,7, 4,7,6,
			0,4,2, 2,4,6,
			0,1,4, 1,5,4
		}
	};
}


