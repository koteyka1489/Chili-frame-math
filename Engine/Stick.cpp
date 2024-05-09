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
		Vec2 startPointWithHeight = startPoint + Vec2{ 0.f, float(i) };
		Vec2 endPointWithHeight = endPoint + Vec2{ 0.f, float(i) };

		Vec2Dir vec(startPointWithHeight, endPointWithHeight);
		gfx.DrawLine(vec, Colors::White);
	}
}

Vec2Dir Stick::GetStickVec() const
{
	return Vec2Dir(endPoint, startPoint);
}

Vec2 Stick::GetStartPoint() const
{
	return startPoint;
}

Vec2 Stick::GetEndPoint() const
{
	return endPoint;
}
