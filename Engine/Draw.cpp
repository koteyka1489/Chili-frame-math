#include "Draw.h"

Draw::Draw(Graphics& gfx)
	:
	gfx(gfx)
{}

void Draw::Init(std::vector<Shape>* shapesUPS)
{
	pShapes = shapesUPS;
	for (int i = 0; i < pShapes->size(); i++)
	{
		points = pShapes->at(i).GetPoints();
	}
}

void Draw::ExecuteDraw()
{

	for (int i = 0; i < points.size() - 1; i++)
	{
		gfx.DrawLine(Vec2Dir{ points[i], points[i + 1] });
	}
	gfx.DrawLine(Vec2Dir{ points.back(), points[0] });
}
