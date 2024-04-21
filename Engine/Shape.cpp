#include "Shape.h"

Shape::Shape()
{
}

void Shape::Update(MainWindow& wnd)
{
	if (!endAddPoints)
	{
		const auto e = wnd.mouse.Read();


		if (e.GetType() == Mouse::Event::Type::LPress)
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

		if (points.size() >= nVert)
		{
			endAddPoints = true;
		}

	}
	else
	{
		SetCenter();
		Move(wnd);
		Scale(wnd);
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

void Shape::SetCenter()
{
	
	float sumX = 0;
	float sumY = 0;
	for (int i = 0; i < points.size(); i++)
	{
		sumX += points[i].x;
		sumY += points[i].y;
	}
	center.x = sumX / points.size();
	center.y = sumY / points.size();
	
}

void Shape::Move(MainWindow& wnd)
{
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		Vec2 dir{ 0.0f, -1.0f };
		dir = dir * speedSqale;
	
		for (int i = 0; i < points.size(); i++)
		{
			points[i] = points[i].AddVec(dir);
		}
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		Vec2 dir{ 0.0f, 1.0f };
		dir = dir * speedSqale;
		for (int i = 0; i < points.size(); i++)
		{
			points[i] = points[i].AddVec(dir);
		}
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		Vec2 dir{ -1.0f, 0.0f };
		dir = dir * speedSqale;
		for (int i = 0; i < points.size(); i++)
		{
			points[i] = points[i].AddVec(dir);
		}
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		Vec2 dir{ 1.0f, 0.0f };
		dir = dir * speedSqale;
		for (int i = 0; i < points.size(); i++)
		{
			points[i] = points[i].AddVec(dir);
		}
	}
}

void Shape::Scale(MainWindow& wnd)
{

	const auto e = wnd.mouse.Read();

	if (e.GetType() == Mouse::Event::Type::WheelUp)
	{
		
		for (int i = 0; i < points.size(); i++)
		{
			Vec2 nv(points[i], center);
			
			nv = nv * sizeScale;
			points[i] = points[i].AddVec(nv);
		}
	}

	if (e.GetType() == Mouse::Event::Type::WheelDown)
	{
		
		for (int i = 0; i < points.size(); i++)
		{
			Vec2 nv(center, points[i]);
			
			nv = nv * sizeScale;
			points[i] = points[i].AddVec(nv);
		}
	}
}




