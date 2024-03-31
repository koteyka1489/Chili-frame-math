#include "Digits.h"

Digits::Digits()
	:
	s0("digits/0.bmp", Colors::White),
	s1("digits/1.bmp", Colors::White),
	s2("digits/2.bmp", Colors::White),
	s3("digits/3.bmp", Colors::White),
	s4("digits/4.bmp", Colors::White),
	s5("digits/5.bmp", Colors::White),
	s6("digits/6.bmp", Colors::White),
	s7("digits/7.bmp", Colors::White),
	s8("digits/8.bmp", Colors::White),
	s9("digits/9.bmp", Colors::White),
	sdot("digits/dot.bmp", Colors::White)
{
}

void Digits::draw_0(int x, int y, Graphics& gfx)
{
	gfx.DrawSpriteChroma(x, y, s0);
}

void Digits::draw_1(int x, int y, Graphics& gfx)
{
	gfx.DrawSpriteChroma(x, y, s1);
}

void Digits::draw_2(int x, int y, Graphics& gfx)
{
	gfx.DrawSpriteChroma(x, y, s2);
}

void Digits::draw_3(int x, int y, Graphics& gfx)
{
	gfx.DrawSpriteChroma(x, y, s3);
}

void Digits::draw_4(int x, int y, Graphics& gfx)
{
	gfx.DrawSpriteChroma(x, y, s4);
}

void Digits::draw_5(int x, int y, Graphics& gfx)
{
	gfx.DrawSpriteChroma(x, y, s5);
}

void Digits::draw_6(int x, int y, Graphics& gfx)
{
	gfx.DrawSpriteChroma(x, y, s6);
}

void Digits::draw_7(int x, int y, Graphics& gfx)
{
	gfx.DrawSpriteChroma(x, y, s7);
}

void Digits::draw_8(int x, int y, Graphics& gfx)
{
	gfx.DrawSpriteChroma(x, y, s8);
}

void Digits::draw_9(int x, int y, Graphics& gfx)
{
	gfx.DrawSpriteChroma(x, y, s9);
}

void Digits::draw_dot(int x, int y, Graphics& gfx)
{
	gfx.DrawSpriteChroma(x, y, sdot);
}

void Digits::draw_0_white(int x, int y, Graphics& gfx)
{
	gfx.DrawSpriteChromaRGBWhite(x, y, s0);
}

void Digits::draw_1_white(int x, int y, Graphics& gfx)
{
	gfx.DrawSpriteChromaRGBWhite(x, y, s1);
}

void Digits::draw_2_white(int x, int y, Graphics& gfx)
{
	gfx.DrawSpriteChromaRGBWhite(x, y, s2);
}

void Digits::draw_3_white(int x, int y, Graphics& gfx)
{
	gfx.DrawSpriteChromaRGBWhite(x, y, s3);
}

void Digits::draw_4_white(int x, int y, Graphics& gfx)
{
	gfx.DrawSpriteChromaRGBWhite(x, y, s4);
}

void Digits::draw_5_white(int x, int y, Graphics& gfx)
{
	gfx.DrawSpriteChromaRGBWhite(x, y, s5);
}

void Digits::draw_6_white(int x, int y, Graphics& gfx)
{
	gfx.DrawSpriteChromaRGBWhite(x, y, s6);
}

void Digits::draw_7_white(int x, int y, Graphics& gfx)
{
	gfx.DrawSpriteChromaRGBWhite(x, y, s7);
}

void Digits::draw_8_white(int x, int y, Graphics& gfx)
{
	gfx.DrawSpriteChromaRGBWhite(x, y, s8);
}

void Digits::draw_9_white(int x, int y, Graphics& gfx)
{
	gfx.DrawSpriteChromaRGBWhite(x, y, s9);
}

void Digits::draw_dot_white(int x, int y, Graphics& gfx)
{
	gfx.DrawSpriteChromaRGBWhite(x, y, sdot);
}

void Digits::DrawNumber(int x, int y, float n, Graphics& gfx)
{
	int intPart = int(n);
	int fractPartInInt = int((n - intPart) * 1000);

	int xStep = 15;
	int nStep = 1;

	int div = 1000;
	
	for (int i = 0; i < 4; i++)
	{
		int num = intPart / div;
		intPart %= div;
		div /= 10;


		switch (num)
		{
		case 0:
			gfx.DrawSpriteChromaRGBWhite(x + xStep * nStep, y, s0);
			break;
		case 1:
			gfx.DrawSpriteChromaRGBWhite(x + xStep * nStep, y, s1);
			break;
		case 2:
			gfx.DrawSpriteChromaRGBWhite(x + xStep * nStep, y, s2);
			break;
		case 3:
			gfx.DrawSpriteChromaRGBWhite(x + xStep * nStep, y, s3);
			break;
		case 4:
			gfx.DrawSpriteChromaRGBWhite(x + xStep * nStep, y, s4);
			break;
		case 5:
			gfx.DrawSpriteChromaRGBWhite(x + xStep * nStep, y, s5);
			break;
		case 6:
			gfx.DrawSpriteChromaRGBWhite(x + xStep * nStep, y, s6);
			break;
		case 7:
			gfx.DrawSpriteChromaRGBWhite(x + xStep * nStep, y, s7);
			break;
		case 8:
			gfx.DrawSpriteChromaRGBWhite(x + xStep * nStep, y, s8);
			break;
		case 9:
			gfx.DrawSpriteChromaRGBWhite(x + xStep * nStep, y, s9);
			break;
		}

		nStep++;
	}

	gfx.DrawSpriteChromaRGBWhite(x + xStep * nStep, y, sdot);
	nStep++;

	div = 100;

	for (int i = 0; i < 3; i++)
	{
		int num = fractPartInInt / div;
		fractPartInInt %= div;
		div /= 10;

		switch (num)
		{
		case 0:
			gfx.DrawSpriteChromaRGBWhite(x + xStep * nStep, y, s0);
			break;
		case 1:
			gfx.DrawSpriteChromaRGBWhite(x + xStep * nStep, y, s1);
			break;
		case 2:
			gfx.DrawSpriteChromaRGBWhite(x + xStep * nStep, y, s2);
			break;
		case 3:
			gfx.DrawSpriteChromaRGBWhite(x + xStep * nStep, y, s3);
			break;
		case 4:
			gfx.DrawSpriteChromaRGBWhite(x + xStep * nStep, y, s4);
			break;
		case 5:
			gfx.DrawSpriteChromaRGBWhite(x + xStep * nStep, y, s5);
			break;
		case 6:
			gfx.DrawSpriteChromaRGBWhite(x + xStep * nStep, y, s6);
			break;
		case 7:
			gfx.DrawSpriteChromaRGBWhite(x + xStep * nStep, y, s7);
			break;
		case 8:
			gfx.DrawSpriteChromaRGBWhite(x + xStep * nStep, y, s8);
			break;
		case 9:
			gfx.DrawSpriteChromaRGBWhite(x + xStep * nStep, y, s9);
			break;
		}

		nStep++;

	}

}
