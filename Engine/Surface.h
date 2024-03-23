#pragma once
#include "Colors.h"
#include <string>

class Surface
{
public:
	Surface(std::string filename, Color chroma);
	Surface(int width, int height);
	Surface(const Surface& rhs);
	Surface& operator=(const Surface& rhs);
	~Surface();
	void PutPixel(int x, int y, Color c);
	Color GetPixel(int x, int y) const;
	int GetWidth() const;
	int GetHeight() const;
	Color GetChromaKey();


private:
	Color* pPixels = nullptr;
	int width;
	int height;
	Color chromaKey;
};

