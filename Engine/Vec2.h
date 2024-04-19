#pragma once
#include <math.h>

class Vec2;

class Point
{
public:
	Point()
		:
		x(0), y(0)
	{}
	Point(float x_in, float y_in)
		:
		x(x_in),
		y(y_in)
	{}
	Point AddVec(const Vec2& v) const;
public:
	float x = 0;
	float y = 0;
};



class Vec2
{
public:
	Vec2();
	Vec2(Point a, Point b);
	Vec2(float x, float y);

	Vec2 operator+(Vec2 rhs) const;
	Vec2 operator-(Vec2 rhs) const;
	Vec2 operator*(float scl) const;
	Vec2 operator/(float scl) const;
	float GetLenghtSqr();
	float GetLenght();
	Vec2 Normalize();
	void SetOrientationCalcMB();


public:
	Point a;
	Point b;
	float xAbsLenght = 0.0f;
	float yAbsLenght = 0.0f;
	bool xRunOrientation = false;
	bool yRiseOrientation = false;
	float m = 0.0f; // rise / run or run / rise 
	float bd = 0.0f; // displacement y or x
	
};

