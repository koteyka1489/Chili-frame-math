#pragma once
#include "Graphics.h"
#include "MainWindow.h"
#include "Vec2.h"


class Stick
{
public:
	Stick();
	void Move(MainWindow& wnd);
	void Draw(Graphics& gfx);
	Vec2Dir GetStickVec() const; 
	Vec2 GetStartPoint() const;
	Vec2 GetEndPoint() const;

private:

	Vec2 startPoint{ 750.0f, 500.f };
	Vec2 endPoint{ 10.f, 300.f };
	int height = 10;
};

