#pragma once
#include <cmath>

class Vec2
{
public:
	Vec2() = default;
	Vec2(float x, float y);

	Vec2 operator+(Vec2 rhs);
	Vec2 operator+(Vec2 rhs) const;
	Vec2 operator+=(Vec2 rhs);
	Vec2 operator-(Vec2 rhs);
	Vec2 operator-(Vec2 rhs) const;
	Vec2 operator-=(Vec2 rhs);
	Vec2 operator*(float scl);
	Vec2 operator*(float scl) const;
	Vec2 operator*=(float scl);
	float operator* (Vec2 rhs);
	Vec2 operator/(float scl);
	Vec2 operator/(float scl) const;
	float GetLenghtSqr() const;
	float GetLenght() const;
	Vec2 Normalize();
	Vec2 Normalize() const;
	void SetOrientationCalcMB();
	//void Rotate(float angle, Point cr);

public:
	float x = 0.f;
	float y = 0.f;

	bool xRunOrientation = false;
	bool yRiseOrientation = false;
	float m = 0.0f; // rise / run or run / rise 
	float bd = 0.0f; // displacement y or x
	
};

