/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"



Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	mInput(wnd),
	kInput(wnd),
	camera(mInput, kInput),
	scrCoordTransformer_2d(camera),
	draw(gfx)
	{
	}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	//float dt = ft.MarkRealDt();
	//t += dt;

	
	mInput.Execute();
	kInput.Execute();
	camera.Update();
	Matrix3 matRotX = matRotX.RotateMatrix3_X(camera.GetThetaRotation_X());
	Matrix3 matRotY = matRotY.RotateMatrix3_Y(camera.GetThetaRotation_Y());
	Matrix3 matRotZ = matRotZ.RotateMatrix3_Z(camera.GetThetaRotation_Z());
	Matrix3 matAllRot = matRotX * matRotY * matRotZ;
	
	if (mInput.GetWheelUp())
	{
		zOffset += { 0.f,0.f, 0.1f };
	}
	if (mInput.GetWheelDown())
	{
		zOffset += { 0.f,0.f, -0.1f };
	}
	
	auto triangles = cube.GetTriangles();

	for (auto& v : triangles.vertices)
	{
		v = matAllRot * v;
		v += {0.f, 0.f, 1.0f};
		v += zOffset;
		sct_3d.Transform(v);
		
	}
	for (size_t i = 0; i < triangles.indexes.size(); i += 3)
	{
		Vec3 v0 = triangles.vertices[triangles.indexes[i]];
		Vec3 v1 = triangles.vertices[triangles.indexes[i + 1]];
		Vec3 v2 = triangles.vertices[triangles.indexes[i + 2]];
		Vec2 v0_2d =  { v0.x, v0.y };
		Vec2 v1_2d =  { v1.x, v1.y };
		Vec2 v2_2d =  { v2.x, v2.y };
		gfx.DrawTriangle(v0_2d, v1_2d, v2_2d, Colors::White);
	}
}

void Game::ComposeFrame()
{
	
}