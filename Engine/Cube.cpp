#include "Cube.h"

Cube::Cube(float size)
{
	float side = size / 2.f;
	vertices.emplace_back( -side,  side,   side);
	vertices.emplace_back(  side,  side,   side);
	vertices.emplace_back(  side,  side,  -side);
	vertices.emplace_back( -side,  side,  -side);
	vertices.emplace_back( -side, -side,   side);
	vertices.emplace_back(  side, -side,   side);
	vertices.emplace_back(  side, -side,  -side);
	vertices.emplace_back( -side, -side,  -side);


}

IndexedLineList Cube::GetLines()
{
	return {
		vertices, {
			0,1, 1,2, 2,3, 3,0, 
			4,5, 5,6, 6,7, 7,4,
			0,4, 1,5, 2,6, 3,7
		}
	};
}
