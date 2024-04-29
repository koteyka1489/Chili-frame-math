#pragma once
#include "Graphics.h"
#include "MainWindow.h"

class Stick
{
public:
	Stick();
	void Move(MainWindow& wnd);
	void Draw(Graphics& gfx);
private:
	float xStart = 750.f;
	float yStart = 500.f;
	float xEnd = 10.f;
	float yEnd = 300.f;
	int height = 10;
};

