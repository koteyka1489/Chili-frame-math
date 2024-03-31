#pragma once
#include "Surface.h"
#include "Graphics.h"

class Digits
{
public:
	Digits();
	void draw_0(int x, int y, Graphics& gfx);
	void draw_1(int x, int y, Graphics& gfx);
	void draw_2(int x, int y, Graphics& gfx);
	void draw_3(int x, int y, Graphics& gfx);
	void draw_4(int x, int y, Graphics& gfx);
	void draw_5(int x, int y, Graphics& gfx);
	void draw_6(int x, int y, Graphics& gfx);
	void draw_7(int x, int y, Graphics& gfx);
	void draw_8(int x, int y, Graphics& gfx);
	void draw_9(int x, int y, Graphics& gfx);
	void draw_dot(int x, int y, Graphics& gfx);

	void draw_0_white(int x, int y, Graphics& gfx);
	void draw_1_white(int x, int y, Graphics& gfx);
	void draw_2_white(int x, int y, Graphics& gfx);
	void draw_3_white(int x, int y, Graphics& gfx);
	void draw_4_white(int x, int y, Graphics& gfx);
	void draw_5_white(int x, int y, Graphics& gfx);
	void draw_6_white(int x, int y, Graphics& gfx);
	void draw_7_white(int x, int y, Graphics& gfx);
	void draw_8_white(int x, int y, Graphics& gfx);
	void draw_9_white(int x, int y, Graphics& gfx);
	void draw_dot_white(int x, int y, Graphics& gfx);

	void DrawNumber(int x, int y, float n, Graphics& gfx);

private:
	Surface s0;
	Surface s1;
	Surface s2;
	Surface s3;
	Surface s4;
	Surface s5;
	Surface s6;
	Surface s7;
	Surface s8;
	Surface s9;
	Surface sdot;
	
};

