#pragma once
#include <vector>
#include "Shape.h"
#include "MainWindow.h"
#include "Vec2.h"


class UpdateScrenCoordinate
{
public:
	UpdateScrenCoordinate() = default;
	UpdateScrenCoordinate(std::vector<Shape>& shapes);
	void Update(MainWindow& wnd);
	void Draw(Graphics& gfx);
private:
	void Move(MainWindow& wnd);
	void Scale(MainWindow& wnd);
	
private:
	std::vector<Shape> shapes;
};

