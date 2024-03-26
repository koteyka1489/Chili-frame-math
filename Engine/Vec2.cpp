#include "Vec2.h"

Point Point::AddVec(const Vec2& v) const
{
	Point nP;
	nP.x = x + v.x;
	nP.y = y + v.y;
	return nP;
}



Vec2::Vec2()
	:
	x(0),
	y(0)
{
}

Vec2::Vec2(Point a, Point b)
{
	x = a.x - b.x;
	y = a.y - b.y;
}

Vec2::Vec2(float x, float y)
	:
	x(x),
	y(y)
{
}

Vec2 Vec2::operator+(Vec2 rhs) const
{
	Vec2 nVec;
	nVec.x = x + rhs.x;
	nVec.y = y + rhs.y;
	return nVec;
}

Vec2 Vec2::operator-(Vec2 rhs) const
{
	Vec2 nVec;
	nVec.x = x - rhs.x;
	nVec.y = y - rhs.y;
	return nVec;
}

Vec2 Vec2::operator*(float scl) const
{
	Vec2 nVec;
	nVec.x = x * scl;
	nVec.y = y * scl;
	return nVec;
}

Vec2 Vec2::operator/(float scl) const
{
	Vec2 nVec;
	nVec.x = x / scl;
	nVec.y = y / scl;
	return nVec;
}

float Vec2::GetLenghtSqr()
{
	return x*x + y * y;
}

float Vec2::GetLenght()
{
	return sqrt(this->GetLenghtSqr());
}

Vec2 Vec2::Normalize()
{
	Vec2 normalize;
	normalize = (*this) / this->GetLenght();
	return normalize;
}


