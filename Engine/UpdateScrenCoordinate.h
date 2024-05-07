#pragma once
#include <vector>
#include "Shape.h"
#include "MainWindow.h"
#include "Vec2.h"
#include "Stick.h"


class UpdateScrenCoordinate
{
public:
	UpdateScrenCoordinate() = default;
	UpdateScrenCoordinate(std::vector<Shape>& shapes);
	UpdateScrenCoordinate operator= (UpdateScrenCoordinate& rhs);

private:

	
private:
	std::vector<Shape>& shapesUPS;

};

