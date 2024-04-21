#pragma once
#include <vector>
#include "Vec2.h"
#include "Graphics.h"
#include "MainWindow.h"


class Shape
{
public:
	Shape();

	void Update(MainWindow& wnd);
	void Draw(Graphics& gfx);

private:
	void SetCenter();
	void Move(MainWindow& wnd);
	void Scale(MainWindow& wnd);


private:
	std::vector<Point> points;
	bool endAddPoints = false;
	static  constexpr int nVert = 5;
	Point center = { 0.0f, 0.0f };
	float speedSqale = 5.0f;
	float sizeScale = 0.1f;
};

