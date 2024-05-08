#pragma once
#include "Vec2.h"

class Rect
{
public:
	Rect(float left, float right, float top, float bott);
	Rect(Vec2 leftTop, float width, float height);
	Rect(Vec2 leftTop, Vec2 rightBott);
	bool InRectCheck(Vec2 p);

public:
	float left;
	float right;
	float top;
	float bott;
};

