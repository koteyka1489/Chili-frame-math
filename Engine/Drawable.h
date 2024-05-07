#pragma once
#include "Vec2.h"
#include <vector>
#include "Graphics.h"

class Drawable
{
public:
	
	
	virtual void Draw() = 0;
	virtual ~Drawable() = 0;

private:
	std::vector<Vec2> points;
	Color clr;
	Vec2 center;
};

