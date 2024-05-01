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

float DistancePointLine(Point p0, Point p1, Point q)
{
	float a = p0.y - p1.y;
	float b = p1.x - p0.x;
	float c = p0.x * p1.y - p1.x * p0.y;

	return std::abs(a * q.x + b * q.y + c) / std::sqrt(a * a + b * b);

}

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	upd(shapesGame)
	{
		for (int i = 0; i < 100; i++)
			{
				shapesGame.emplace_back(750.f, 900.f, 32, 10, Colors::White);
			}
		
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

	if (ticks >= ticksMax)
	{
		curShape++;
		ticks = 0;
	}
	else
	{
		ticks++;
	}
	
	for (int i = 0; i <= curShape; i++)
	{
		
		if (DistancePointLine(stick.GetStartPoint(), stick.GetEndPoint(), shapesGame[i].GetCenter()) < shapesGame[i].GetRadius() 
			&& !shapesGame[i].GetRebounded())
		{
			collideSound.Play();
			Vec2 w = stick.GetStickVec().Normalize();
			Vec2 v = shapesGame[i].GetSpeed();
			shapesGame[i].SetSpeed(w * (v * w) * 2.f - v);
			shapesGame[i].SetRebounded(true);
		}
		shapesGame[i].Move();
	}
	stick.Move(wnd);
	upd = UpdateScrenCoordinate{ shapesGame };
	upd.Update(wnd);
}

void Game::ComposeFrame()
{
	upd.Draw(gfx);
	stick.Draw(gfx);
}