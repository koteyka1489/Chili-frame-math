#include "Vec2.h"

Point Point::operator+(const Point& rhs)
{

	return Point(this->x + rhs.x, this->y + rhs.y);
}

Point Point::AddVec(const Vec2& v) const
{
	Point nP;
	nP.x = x + v.xAbsLenght;
	nP.y = y + v.yAbsLenght;
	return nP;
}



Vec2::Vec2()
	:
	xAbsLenght(0),
	yAbsLenght(0),
	a(0,0),
	b(0,0)
{}

Vec2::Vec2(Point a, Point b)
	:
	a(a),
	b(b),
	xAbsLenght(a.x - b.x),
	yAbsLenght(a.y - b.y)
{}

Vec2::Vec2(float x, float y)
	:
	a(0.0f, 0.0f),
	b(0.0f, 0.0f),
	xAbsLenght(x),
	yAbsLenght(y)
{}



Vec2 Vec2::operator+(Vec2 rhs) const
{
	Vec2 nVec;
	nVec.xAbsLenght = xAbsLenght + rhs.xAbsLenght;
	nVec.yAbsLenght = yAbsLenght + rhs.yAbsLenght;
	return nVec;
}

Vec2 Vec2::operator-(Vec2 rhs) const
{
	Vec2 nVec;
	nVec.xAbsLenght = xAbsLenght - rhs.xAbsLenght;
	nVec.yAbsLenght = yAbsLenght - rhs.yAbsLenght;
	return nVec;
}

Vec2 Vec2::operator*(float scl) const
{
	Vec2 nVec;
	nVec.xAbsLenght = xAbsLenght * scl;
	nVec.yAbsLenght = yAbsLenght * scl;
	return nVec;
}

float Vec2::operator*(Vec2 rhs)
{
	return xAbsLenght * rhs.xAbsLenght + yAbsLenght * rhs.yAbsLenght;
}



Vec2 Vec2::operator/(float scl) const
{
	Vec2 nVec;
	nVec.xAbsLenght = xAbsLenght / scl;
	nVec.yAbsLenght = yAbsLenght / scl;
	return nVec;
}

float Vec2::GetLenghtSqr()
{
	return xAbsLenght * xAbsLenght + yAbsLenght * yAbsLenght;
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

void Vec2::SetOrientationCalcMB()
{
	float mv; 
	mv = (a.y - b.y) / (a.x - b.x);
	if (abs((int)mv) <= 1)
	{
		xRunOrientation = true;
		m = mv;
		bd = a.y - (a.x * mv);
	}
	else
	{
		yRiseOrientation = true;
		m = (a.x - b.x) / (a.y - b.y);
		bd = a.x - (a.y * m);
	}

}


