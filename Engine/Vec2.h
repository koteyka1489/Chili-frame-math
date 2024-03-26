#pragma once
#include <math.h>

class Vec2;

class Point
{
public:
	Point()
		:x(0), y(0)
	{}
	Point(float x_in, float y_in)
		:x(x_in), y(y_in)
	{}
	Point AddVec(const Vec2& v) const;
public:
	float x, y;
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


public:
	float x;
	float y;
	
};

