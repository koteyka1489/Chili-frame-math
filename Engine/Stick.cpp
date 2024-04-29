#include "Stick.h"

Stick::Stick()
{
}

void Stick::Move(MainWindow& wnd)
{ 
	if (wnd.kbd.KeyIsPressed(VK_SHIFT))
	{
		endPoint.y += -5.0f;
	}
	if (wnd.kbd.KeyIsPressed(VK_CONTROL))
	{
		endPoint.y += 5.0f;
	}
}

void Stick::Draw(Graphics& gfx)
{
	for (int i = 0; i < height; i++)
	{
		Point startPointWithHeight = startPoint + Point{ 0.f, float(i) };
		Point endPointWithHeight = endPoint + Point{ 0.f, float(i) };

		Vec2 vec(startPointWithHeight, endPointWithHeight);
		gfx.DrawLine(vec);
	}
}

Vec2 Stick::GetStickVec()
{
	return Vec2(endPoint, startPoint);
}

Point Stick::GetStartPoint()
{
	return startPoint;
}

Point Stick::GetEndPoint()
{
	return endPoint;
}
