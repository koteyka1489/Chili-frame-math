#pragma once
#include <vector>
#include "Vec3.h"
#include "Vec2.h"
#include <cassert>

struct  IndexedTriangleList
{
	IndexedTriangleList(std::vector<Vec3> vertices_in, std::vector<size_t> indexes_in)
		:
		vertices(vertices_in),
		indexes(indexes_in)
	{
		assert(vertices.size() > 2);
		assert(indexes.size() % 3 == 0);
		flags.resize(indexes.size() * 3);
		std::fill(flags.begin(), flags.end(), false);
	}
	std::vector<Vec3> vertices;
	std::vector<size_t> indexes;
	std::vector<bool> flags;
};