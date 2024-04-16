#pragma once
#include <vector>
#include "Vec2.h"
#include "Graphics.h"
#include "MainWindow.h"


class Shape
{
public:
	Shape();

	void AddPoints(MainWindow& wnd);
	void Draw(Graphics& gfx);

private:
	std::vector<Point> points;
	bool endAddPoints = false;

};

