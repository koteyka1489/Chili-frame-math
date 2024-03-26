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
	dg("numbers.bmp", Colors::White),
	leftTop(curRectLeft, 0.0f),
	rightBott(curRecRight, 40.0f),
	dgRec(leftTop, rightBott)
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
	
	if (curTicks == ticksMax)
	{
		curTicks = 0;
		if (dCounter < dCounterMax)
		{
			dCounter++;

		}
		else
		{
			dCounter = 0;
		}
		
		curRectLeft = widthStep * dCounter;
		curRecRight = widthStep * dCounter + 50.0f;
		dgRec = { curRectLeft, curRecRight, 0.0f, 40.0f };
	}
	else
	{
		curTicks++;
	}


	

}

void Game::ComposeFrame()
{
	

	gfx.DrawSpriteChromaRect(100, 100, dg, dgRec);


}
