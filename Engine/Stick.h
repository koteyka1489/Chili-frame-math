#pragma once
#include "Graphics.h"
#include "MainWindow.h"
#include "Vec2.h"


class Stick
{
public:
	Stick();
	void Move(MainWindow& wnd);
	void Draw(Graphics& gfx);
	Vec2 GetStickVec();
	Point GetStartPoint();
	Point GetEndPoint();

private:

	Point startPoint{ 750.0f, 500.f };
	Point endPoint{ 10.f, 300.f };
	int height = 10;
};

