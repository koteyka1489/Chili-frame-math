#include "Draw.h"

Draw::Draw(Graphics& gfx)
	:
	gfx(gfx)
{}

void Draw::Init(std::vector<Shape>* shapesUPS)
{
	pShapes = shapesUPS;

}

void Draw::ExecuteDraw()
{
	for (int i = 0; i < pShapes->size(); i++)
	{
		std::vector<Vec2> points;
		points = pShapes->operator[](i).GetPoints();
		Color color = pShapes->operator[](i).GetColor();

		for (int i = 0; i < points.size() - 1; i++)
		{
			gfx.DrawLine(Vec2Dir{ points[i], points[i + 1] }, color);
		}
		gfx.DrawLine(Vec2Dir{ points.back(), points[0] }, color);

	}

}
