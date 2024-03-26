#include "Rect.h"

Rect::Rect(float left, float right, float top, float bott)
	:
	left(left),
	right(right),
	top(top),
	bott(bott)
{}

Rect::Rect(Point leftTop, float width, float height)
	:
	Rect(leftTop.x, leftTop.x + width, leftTop.y, leftTop.y + height)
{}

Rect::Rect(Point leftTop, Point rightBott)
	:
	Rect(leftTop.x, rightBott.x, leftTop.y, rightBott.y)
{}
