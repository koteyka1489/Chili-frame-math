/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Surface.h"
#include "Vec2.h"
#include "Rect.h"
#include "Digits.h"
#include "Button.h"
#include "FrameTimer.h"
#include "Shape.h"
#include "ScreenCoordinateTransformer_2D.h"
#include "Stick.h"
#include <cmath>
#include "Sound.h"
#include "Camera.h"
#include "Input.h"
#include "Draw.h"
#include "XMath.h"
#include "ScreenCoordinateTransformer_3D.h"
#include "Cube.h"



class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();

private:
	MainWindow& wnd;
	Graphics gfx;
	FrameTimer ft;
	std::vector<Shape> shapesGame;
	MouseInput mInput;
	KeyboardInput kInput;
	Camera camera;
	ScreenCoordinateTransformer_2D scrCoordTransformer_2d;
	Draw draw;
	int ticks = 0;
	int ticksMax = 180;
	int curShape = 0;
	Stick stick;
	float t = 0.f;
	Cube cube0{ 0.5f };
	Cube cube1{ 0.3f };
	Cube cube2{ 0.6f };
	ScreenCoordinateTransformer_3D sct_3d;
	Vec3 zOffset{ 0.f, 0.f, 0.f };
	std::vector<Color> colorsm;
	
	
};