#pragma once
#include "Surface.h"
#include "Graphics.h"
#include "MainWindow.h"

class Button
{
public:
	Button(int x, int y);
	void Draw(Graphics& gfx);
	void MoveButton(MainWindow& wnd);
	float GetDamageValue();

private:
	void DrawLine(Graphics& gfx);
	void DrawButton(Graphics& gfx);

private:
	Surface but;
	Surface line;
	const int xLineStart;
	const int yLineStart;
	const int xButtonStart;	
	const int yButtonStart;
	int xButton;
};

