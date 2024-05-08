#include "Button.h"

Button::Button(int x, int y)
	:
	but("button/button.bmp", Colors::White),
	line("button/line.bmp", Colors::White),
	xLineStart(x),
	yLineStart(y),
	xButtonStart(x),
	yButtonStart(y),
	xButton(x)
{
}

void Button::Draw(Graphics& gfx)
{
	DrawLine( gfx);
	DrawButton(gfx);
}

void Button::MoveButton(MainWindow& wnd)
{


	if (wnd.mouse.LeftIsPressed())
	{
		Rect buttonRect(Vec2((float)xButton, (float)yButtonStart), 100.0f, 92.0f);
		Vec2 mousePoint((float)wnd.mouse.GetPosX(), (float)wnd.mouse.GetPosY());
		if (buttonRect.InRectCheck(mousePoint))
		{
			
			xButton = wnd.mouse.GetPosX() - 50;
			if (xButton < xButtonStart)
			{
				xButton = xButtonStart;
			}
			if (xButton > xButtonStart + 335)
			{
				xButton = xButtonStart + 335;
			}
				
		}
	}
	
}

float Button::GetDamageValue()
{
	int strench = xButton - 100;

	return (3/2) * strench + 10;
}

void Button::DrawLine( Graphics& gfx)
{
	gfx.DrawSpriteChroma(xLineStart, yLineStart, line);
}

void Button::DrawButton( Graphics& gfx)
{
	gfx.DrawSpriteChroma(xButton, yButtonStart, but);
}
