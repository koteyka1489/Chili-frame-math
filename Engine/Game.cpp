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
	gfx( wnd )
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
	float dt = ft.MarkRealDt();
	t += dt;
	float theta =  t * 3.14159;
	std::vector<Shape> triang;
	triang.emplace_back(0.f, 0.f, 3, 150, Colors::Cyan);
	triang.emplace_back(800.f, 200.f, 6, 150, Colors::Cyan);
	triang.emplace_back(1500.f, 0.f, 4, 150, Colors::Cyan);
	triang.emplace_back(0.f, 1000.0f, 5, 150, Colors::Cyan);
	triang.emplace_back(1000.f, 1500.0f, 3, 150, Colors::Cyan);
	triang.emplace_back(1800.f, 300.0f, 8, 150, Colors::Cyan);
	triang.emplace_back(0.f, 800.0f, 4, 150, Colors::Cyan);
	triang.emplace_back(500.f, 200.0f, 10, 150, Colors::Cyan);
	triang.emplace_back(1400.f, 1500.0f, 6, 150, Colors::Cyan);


	for (int i = 0; i < triang.size(); i++)
	{
		triang[i].Rotate(theta + i / 0.1f);
	}
	
	camera.Update(wnd);

	for (int i = 0; i < triang.size(); i++)
	{
		triang[i].Draw(gfx, camera.GetOffset(), camera.GetScaleCameraMod(), camera.GetThetaRotation(), Point{0.0f, 0.0f});
	}

	

}

void Game::ComposeFrame()
{
	

}