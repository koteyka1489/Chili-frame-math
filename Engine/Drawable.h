#pragma once
#include "Vec2.h"
#include <vector>
#include "Graphics.h"

class Drawable
{
public:
	
	
	virtual void Draw() = 0;
	virtual void Update() = 0;
	virtual ~Drawable() = 0;

};

