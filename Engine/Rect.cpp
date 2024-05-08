#include "Rect.h"

Rect::Rect(float left, float right, float top, float bott)
	:
	left(left),
	right(right),
	top(top),
	bott(bott)
{}

Rect::Rect(Vec2 leftTop, float width, float height)
	:
	Rect(leftTop.x, leftTop.x + width, leftTop.y, leftTop.y + height)
{}

Rect::Rect(Vec2 leftTop, Vec2 rightBott)
	:
	Rect(leftTop.x, rightBott.x, leftTop.y, rightBott.y)
{}

bool Rect::InRectCheck(Vec2 p)
{
	return p.x >= left && p.x <= right && p.y >= top && p.y <= bott;
}
