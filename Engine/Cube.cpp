#include "Cube.h"

Cube::Cube(float size)
{
	float side = size / 2.f;
	vertices.emplace_back(-side, -side, -side);
	vertices.emplace_back( side, -side, -side);
	vertices.emplace_back(-side,  side, -side);
	vertices.emplace_back( side,  side, -side);
	vertices.emplace_back(-side, -side,  side);
	vertices.emplace_back( side, -side,  side);
	vertices.emplace_back(-side,  side,  side);
	vertices.emplace_back( side,  side,  side);


}

IndexedLineList Cube::GetLines()
{
	return {
		vertices, {
			0, 1, 1, 3, 3, 2, 2, 0, // ѕередн€€ грань
			4, 5, 5, 7, 7, 6, 6, 4, // «адн€€ грань
			0, 4, 1, 5, 3, 7, 2, 6  // —оединени€ между передней и задней гран€ми
		}
	};
}
