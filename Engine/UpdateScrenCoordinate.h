#pragma once
#include <vector>
#include "Shape.h"
#include "MainWindow.h"
#include "Vec2.h"
#include "Stick.h"
#include "Camera.h"


class UpdateScrenCoordinate
{
public:
	UpdateScrenCoordinate() = default;
	UpdateScrenCoordinate(std::vector<Drawable> shapesIN, Camera& cam);
	UpdateScrenCoordinate operator= (UpdateScrenCoordinate& rhs);
	void Update();
private:

	
private:
	std::vector<Drawable> shapesUPS;
	Camera& cam;
};

