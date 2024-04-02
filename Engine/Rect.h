#pragma once
#include "Vec2.h"

class Rect
{
public:
	Rect(float left, float right, float top, float bott);
	Rect(Point leftTop, float width, float height);
	Rect(Point leftTop, Point rightBott);
	bool InRectCheck(Point p);

public:
	float left;
	float right;
	float top;
	float bott;
};

