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
	shapesGame.emplace_back(-300.0f, -500.0f, 3, 50, Colors::White);
	shapesGame.emplace_back(-200.0f, 300.0f, 4, 50, Colors::Cyan);
	shapesGame.emplace_back(-100.0f, -400.0f, 5, 50, Colors::Blue);
	shapesGame.emplace_back(0.0f, 0.0f, 6, 50, Colors::Red);
	shapesGame.emplace_back(100.0f, -500.0f, 5, 50, Colors::Gray);
	shapesGame.emplace_back(200.0f, 200.0f, 3, 50, Colors::Green);
	shapesGame.emplace_back(300.0f, -500.0f, 5, 50, Colors::LightGray);
	shapesGame.emplace_back(400.0f, 100.0f, 10, 50, Colors::Yellow);
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
	
	//scrCoordTransformer_2d.Init(shapesGame);
	//scrCoordTransformer_2d.Update();
	//draw.Init(scrCoordTransformer_2d.GetShapes());
	
	mInput.Execute();
	kInput.Execute();
	camera.Update();
	Matrix3 matRotX = matRotX.RotateMatrix3_X(camera.GetThetaRotation_X());
	Matrix3 matRotY = matRotY.RotateMatrix3_Y(camera.GetThetaRotation_Y());
	Matrix3 matRotZ = matRotZ.RotateMatrix3_Z(camera.GetThetaRotation_Z());
	Matrix3 matAllRot = matRotX * matRotY * matRotZ;

	
	
	auto lines = cube.GetLines();

	for (auto& v : lines.vertices)
	{
		
		v = matAllRot * v;
		v += {0.f, 0.f, 1.f};
		
		sct_3d.Transform(v);
	}
	for (size_t i = 0; i < lines.indexes.size(); i += 2)
	{
		Vec3 endPoint = lines.vertices[lines.indexes[i + 1]];
		Vec3 startPoint = lines.vertices[lines.indexes[i]];

		Vec2 endPoint2D = { endPoint.x, endPoint.y };
		Vec2 startPoint2D = { startPoint.x, startPoint.y };

		Vec2Dir vec(endPoint2D, startPoint2D);
		gfx.DrawLine(vec, Colors::White);
	}


}

void Game::ComposeFrame()
{
	//draw.ExecuteDraw();
}