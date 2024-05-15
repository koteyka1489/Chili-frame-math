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



Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	mInput(wnd),
	kInput(wnd),
	camera(mInput, kInput),
	scrCoordTransformer_2d(camera),
	draw(gfx)
	{
		colorsm.push_back(Colors::Blue);
		colorsm.push_back(Colors::Red);
		colorsm.push_back(Colors::Green);
		colorsm.push_back(Colors::Yellow);
		colorsm.push_back(Colors::Blue);
		colorsm.push_back(Colors::Red);
		colorsm.push_back(Colors::Green);
		colorsm.push_back(Colors::Yellow);
		colorsm.push_back(Colors::Blue);
		colorsm.push_back(Colors::Red);
		colorsm.push_back(Colors::Green);
		colorsm.push_back(Colors::Yellow);
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
	
	auto triangles0 = cube0.GetTriangles();
	auto triangles1 = cube1.GetTriangles();
	auto triangles2 = cube2.GetTriangles();


	for (auto& v0 : triangles0.vertices)
	{
		v0 = matAllRot * v0;
		v0 += {1.f, 1.f, 5.0f};
		v0 += zOffset;
	}
	for (auto& v1 : triangles1.vertices)
	{
		v1 = matAllRot * v1;
		v1 += {-1.f, -1.f, 3.0f};
		v1 += zOffset;
	}
	for (auto& v2 : triangles2.vertices)
	{
		v2 = matAllRot * v2;
		v2 += {1.f, -1.f, 6.0f};
		v2 += zOffset;
	}



	for (size_t i = 0; i < triangles0.indexes.size(); i += 3)
	{
		Vec3 v0 = triangles0.vertices[triangles0.indexes[i]];
		Vec3 v1 = triangles0.vertices[triangles0.indexes[i + 1]];
		Vec3 v2 = triangles0.vertices[triangles0.indexes[i + 2]];
		Vec3Dir v0Dir{ v1, v0 };
		Vec3Dir v1Dir{ v2, v0 };
		Vec3Dir vCp = vCp.CrossProduct(v0Dir, v1Dir);
		Vec3Dir vecCamera{ v0 , Vec3{0.f, 0.f, 0.f } };
		if (vCp.DotProduct(vecCamera) >= 0.f)
		{
			triangles0.flags[i / 3] = true;
		}
	}
	for (size_t i = 0; i < triangles1.indexes.size(); i += 3)
	{
		Vec3 v0 = triangles1.vertices[triangles1.indexes[i]];
		Vec3 v1 = triangles1.vertices[triangles1.indexes[i + 1]];
		Vec3 v2 = triangles1.vertices[triangles1.indexes[i + 2]];
		Vec3Dir v0Dir{ v1, v0 };
		Vec3Dir v1Dir{ v2, v0 };
		Vec3Dir vCp = vCp.CrossProduct(v0Dir, v1Dir);
		Vec3Dir vecCamera{ v0 , Vec3{0.f, 0.f, 0.f } };
		if (vCp.DotProduct(vecCamera) >= 0.f)
		{
			triangles1.flags[i / 3] = true;
		}
	}
	for (size_t i = 0; i < triangles2.indexes.size(); i += 3)
	{
		Vec3 v0 = triangles2.vertices[triangles2.indexes[i]];
		Vec3 v1 = triangles2.vertices[triangles2.indexes[i + 1]];
		Vec3 v2 = triangles2.vertices[triangles2.indexes[i + 2]];
		Vec3Dir v0Dir{ v1, v0 };
		Vec3Dir v1Dir{ v2, v0 };
		Vec3Dir vCp = vCp.CrossProduct(v0Dir, v1Dir);
		Vec3Dir vecCamera{ v0 , Vec3{0.f, 0.f, 0.f } };
		if (vCp.DotProduct(vecCamera) >= 0.f)
		{
			triangles2.flags[i / 3] = true;
		}
	}


	for (auto& v : triangles0.vertices)
	{
		sct_3d.Transform(v);
	}
	for (size_t i = 0; i < triangles0.indexes.size(); i += 3)
	{
		if (!triangles0.flags[i / 3])
		{
			Vec3 v0 = triangles0.vertices[triangles0.indexes[i]];
			Vec3 v1 = triangles0.vertices[triangles0.indexes[i + 1]];
			Vec3 v2 = triangles0.vertices[triangles0.indexes[i + 2]];
			Vec2 v0_2d = { v0.x, v0.y };
			Vec2 v1_2d = { v1.x, v1.y };
			Vec2 v2_2d = { v2.x, v2.y };
			gfx.DrawTriangle(v0_2d, v1_2d, v2_2d, colorsm[i / 3]);
		}
	}


	for (auto& v : triangles1.vertices)
	{
		sct_3d.Transform(v);
	}
	for (size_t i = 0; i < triangles1.indexes.size(); i += 3)
	{
		if (!triangles1.flags[i / 3])
		{
			Vec3 v0 = triangles1.vertices[triangles1.indexes[i]];
			Vec3 v1 = triangles1.vertices[triangles1.indexes[i + 1]];
			Vec3 v2 = triangles1.vertices[triangles1.indexes[i + 2]];
			Vec2 v0_2d = { v0.x, v0.y };
			Vec2 v1_2d = { v1.x, v1.y };
			Vec2 v2_2d = { v2.x, v2.y };
			gfx.DrawTriangle(v0_2d, v1_2d, v2_2d, colorsm[i / 3]);
		}
	}

	for (auto& v : triangles2.vertices)
	{
		sct_3d.Transform(v);
	}
	for (size_t i = 0; i < triangles2.indexes.size(); i += 3)
	{
		if (!triangles2.flags[i / 3])
		{
			Vec3 v0 = triangles2.vertices[triangles2.indexes[i]];
			Vec3 v1 = triangles2.vertices[triangles2.indexes[i + 1]];
			Vec3 v2 = triangles2.vertices[triangles2.indexes[i + 2]];
			Vec2 v0_2d = { v0.x, v0.y };
			Vec2 v1_2d = { v1.x, v1.y };
			Vec2 v2_2d = { v2.x, v2.y };
			gfx.DrawTriangle(v0_2d, v1_2d, v2_2d, colorsm[i / 3]);
		}
	}
}

void Game::ComposeFrame()
{
	
}