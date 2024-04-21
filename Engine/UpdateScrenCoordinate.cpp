#include "UpdateScrenCoordinate.h"

UpdateScrenCoordinate::UpdateScrenCoordinate(std::vector<Shape>& shapes)
	:
	shapes(std::move(shapes))
{}

void UpdateScrenCoordinate::Update(MainWindow & wnd)
{
	Move(wnd);
	Scale(wnd);
}

void UpdateScrenCoordinate::Move(MainWindow& wnd)
{
	Vec2 dir{ 0.0f, 0.0f };

	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		dir = dir + Vec2{ 0.0f, 5.0f };

	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		dir = dir + Vec2{ 0.0f, -5.0f };

	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		dir = dir + Vec2{ 5.0f, 0.0f };
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		dir = dir + Vec2{ -5.0f, 0.0f };
	}
	
	for (int i = 0; i < shapes.size(); i++)
	{
		shapes[i].Move(wnd, dir);
	}

}

void UpdateScrenCoordinate::Scale(MainWindow& wnd)
{
	const auto e = wnd.mouse.Read();

	if (e.GetType() == Mouse::Event::Type::WheelUp)
	{
		for (int i = 0; i < shapes.size(); i++)
		{
			shapes[i].ScaleFromCenterShape(wnd, true);
		}
	}
	if (e.GetType() == Mouse::Event::Type::WheelDown)
	{
		for (int i = 0; i < shapes.size(); i++)
		{
			shapes[i].ScaleFromCenterShape(wnd, false);
		}
	}

}

void UpdateScrenCoordinate::Draw(Graphics& gfx)
{
	for (int i = 0; i < shapes.size(); i++)
	{
		shapes[i].Draw(gfx);
	}
}
