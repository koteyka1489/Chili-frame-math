#pragma once
#include <vector>
#include "Shape.h"
#include "MainWindow.h"
#include "Vec2.h"
#include "Stick.h"
#include "Camera.h"
#include "XMath.h"


class UpdateScrenCoordinate
{
public:
	UpdateScrenCoordinate() = default;
	UpdateScrenCoordinate(Camera& camera_in);
	UpdateScrenCoordinate operator= (UpdateScrenCoordinate& rhs);
	void Init(std::vector<Shape> shapesIN);
	void Update();
	std::vector<Shape>* GetShapes();
private:

	
private:
	Camera& camera;
	std::vector<Shape> shapesUPS;
	std::vector<Stick> stick;
};

