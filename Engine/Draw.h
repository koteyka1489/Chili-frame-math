#pragma once
#include "Graphics.h"
#include <vector>
#include "Shape.h"

class Draw
{
public:
	Draw(Graphics& gfx);
	void Init(std::vector<Shape>* shapesUPS);
	void ExecuteDraw();

private:
	Graphics& gfx;
	std::vector<Shape>* pShapes = nullptr;
	std::vector<Vec2> points;
};

