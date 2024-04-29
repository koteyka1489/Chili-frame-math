#pragma once
#include <vector>
#include "Vec2.h"
#include "Graphics.h"
#include "MainWindow.h"


class Shape
{
public:
	Shape();
	Shape(float x, float y, int nVert, float radius, Color clr);

	void Update(MainWindow& wnd);
	void Draw(Graphics& gfx);

	void SetCenter();
	void UpdateSpeed(Vec2 dir);
	void Move();
	void ScaleFromCenterShape(MainWindow& wnd, bool dir);
	Point GetCenter();
	float GetRadius();
	Vec2 GetSpeed();
	void SetSpeed(Vec2 speed_in);


private:
	std::vector<Point> points;
	Color clr = Colors::White;
	bool endAddPoints = false;
	static  constexpr int nVert = 5;
	Point center = { 0.0f, 0.0f };
	float radius = 0.0f;
	float speedSqale = 5.0f;
	float sizeScale = 0.1f;
	Vec2 speedVec = { -2.5f, -5.f };
};

