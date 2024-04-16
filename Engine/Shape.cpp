#include "Shape.h"

Shape::Shape()
{
}

void Shape::AddPoints(MainWindow& wnd)
{
	if (!endAddPoints)
	{

		if (wnd.mouse.LeftIsPressed())
		{

			if (!points.empty())
			{
				if (points[points.size() - 1].x != wnd.mouse.GetPosX() || points[points.size() - 1].y != wnd.mouse.GetPosY())
				{
					points.emplace_back(wnd.mouse.GetPosX(), wnd.mouse.GetPosY());
				}
			}
			else
			{
				points.emplace_back(wnd.mouse.GetPosX(), wnd.mouse.GetPosY());
			}
		
			

		}

		if (points.size() >= 10)
		{
			endAddPoints = true;
		}

	}
	if (wnd.kbd.KeyIsPressed(VK_SPACE))
	{
		endAddPoints = false;
		points.clear();
	}
}

void Shape::Draw(Graphics& gfx)
{
	if (!points.empty() && !endAddPoints)
	{
		for (int i = 0; i < points.size(); i++)
		{
			gfx.PutPixel(points[i].x, points[i].y, Colors::White);
		}
	}

	if (endAddPoints)
	{
		for (int i = 0; i < points.size() - 1; i++)
		{
			Vec2 vec(points[i], points[i + 1]);
			gfx.DrawLine(vec);
		}

		Vec2 vecEnd(points[points.size() - 1], points[0]);
		gfx.DrawLine(vecEnd);
	}
}




