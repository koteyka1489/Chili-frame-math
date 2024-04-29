#pragma once
#include <vector>
#include "Shape.h"
#include "MainWindow.h"
#include "Vec2.h"


class UpdateScrenCoordinate
{
public:
	UpdateScrenCoordinate();
	UpdateScrenCoordinate(std::vector<Shape>& shapes);
	UpdateScrenCoordinate operator= (UpdateScrenCoordinate& rhs);
	void Update(MainWindow& wnd);
	void Draw(Graphics& gfx);
private:
	void Move(MainWindow& wnd);
	void Scale(MainWindow& wnd);
	
private:
	std::vector<Shape> sh;
	std::vector<Shape>& shapesUPS;
	
};

