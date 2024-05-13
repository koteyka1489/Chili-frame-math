#pragma once
#include <vector>
#include "Shape.h"
#include "MainWindow.h"
#include "Vec2.h"
#include "Stick.h"
#include "Camera.h"
#include "XMath.h"


class ScreenCoordinateTransformer_2D
{
public:
	ScreenCoordinateTransformer_2D() = default;
	ScreenCoordinateTransformer_2D(Camera& camera_in);
	ScreenCoordinateTransformer_2D operator= (ScreenCoordinateTransformer_2D& rhs);
	void Init(std::vector<Shape> shapesIN);
	void Update();
	std::vector<Shape>* GetShapes();
private:

	
private:
	Camera& camera;
	std::vector<Shape> shapesUPS;
	std::vector<Stick> stick;
};

