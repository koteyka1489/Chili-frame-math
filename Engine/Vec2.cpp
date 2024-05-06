#include "Vec2.h"




Vec2::Vec2(float x, float y)
	:
	x(x),
	y(y)
{}

Vec2 Vec2::operator+(Vec2 rhs)
{
	x += rhs.x;
	y += rhs.y;
	return *this;
}

Vec2 Vec2::operator+(Vec2 rhs) const
{
	Vec2 nVec;
	nVec = (*this) + rhs;
	return nVec;
}

Vec2 Vec2::operator+=(Vec2 rhs)
{
	return (*this) + rhs;
}

Vec2 Vec2::operator-(Vec2 rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	return *this;
}

Vec2 Vec2::operator-(Vec2 rhs) const
{
	Vec2 nVec = (*this) - rhs;
	return nVec;
}

Vec2 Vec2::operator-=(Vec2 rhs)
{
	return (*this) - rhs;
}

Vec2 Vec2::operator*(float scl)
{
	x *= scl;
	y *= scl;
	return *this;
}

Vec2 Vec2::operator*(float scl) const
{
	Vec2 nVec = (*this) * scl;
	return nVec;
}

Vec2 Vec2::operator*=(float scl)
{
	return (*this) * scl;
}

float Vec2::operator*(Vec2 rhs)
{
	return x * rhs.x + y * rhs.y;
}

Vec2 Vec2::operator/(float scl)
{
	x /= scl;
	y /= scl;
	return *this;
}



Vec2 Vec2::operator/(float scl) const
{
	Vec2 nVec = (*this) * scl;
	return nVec;
}

float Vec2::GetLenghtSqr() const
{
	return x * x + y * y;
}

float Vec2::GetLenght() const
{
	return sqrt(this->GetLenghtSqr());
}

Vec2 Vec2::Normalize()
{
	
	if (this->GetLenght() != 0.f)
	{
		*this = (*this) / this->GetLenght();
	}
	return *this;
}

Vec2 Vec2::Normalize() const
{
	Vec2 normalize;
	if (this->GetLenght() != 0.f)
	{
		normalize = (*this) / this->GetLenght();
	}
	return normalize;
}

void Vec2::SetOrientationCalcMB()
{
	float mv; 
	mv = y / x;
	if (abs((int)mv) <= 1)
	{
		xRunOrientation = true;
		m = mv;
		bd = y - (x * mv);
	}
	else
	{
		yRiseOrientation = true;
		m = x / y;
		bd = x - (y * m);
	}

}




