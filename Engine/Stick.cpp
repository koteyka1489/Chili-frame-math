#include "Stick.h"

Stick::Stick()
{
}

void Stick::Move(MainWindow& wnd)
{ 
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		yEnd += -5.0f;
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		yEnd += 5.0f;
	}
}

void Stick::Draw(Graphics& gfx)
{
	for (int i = 0; i < height; i++)
	{
		Vec2 vec(Point{xStart, yStart - i}, Point{xEnd, yEnd - i});
		gfx.DrawLine(vec);
	}
}
