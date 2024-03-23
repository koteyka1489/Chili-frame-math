#pragma once
#include "Colors.h"

class Surface
{
public:
	Surface(int width, int height);
	Surface(const Surface& rhs);
	Surface& operator=(const Surface& rhs);
	~Surface();
	void PutPixel(int x, int y, Color c);
	Color GetPixel(int x, int y) const;
	int GetWidth() const;
	int GetHeight() const;


private:
	Color* pPixels = nullptr;
	int width = 0;
	int height = 0;
};

