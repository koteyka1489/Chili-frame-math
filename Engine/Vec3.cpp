#include "Vec3.h"

Vec3::Vec3(float x, float y, float z)
	:
	x(x),
	y(y),
	z(y)
{}


Vec3 Vec3::operator+(Vec3 rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	return *this;
}

Vec3 Vec3::operator+(Vec3 rhs) const
{
	Vec3 nVec;
	nVec = (*this) + rhs;
	return nVec;
}

Vec3 Vec3::operator+=(Vec3 rhs)
{
	return (*this) + rhs;
}

Vec3 Vec3::operator+(Vec3Dir rhs)
{
	x += rhs.xLen;
	y += rhs.yLen;
	z += rhs.zLen;
	return *this;
}

Vec3 Vec3::operator+=(Vec3Dir rhs)
{

	return (*this) + rhs;
}

Vec3 Vec3::operator-(Vec3 rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	return *this;
}

Vec3 Vec3::operator-(Vec3 rhs) const
{
	Vec3 nVec = (*this) - rhs;
	return nVec;
}

Vec3 Vec3::operator-=(Vec3 rhs)
{
	return (*this) - rhs;
}

Vec3 Vec3::operator*(float scl)
{
	x *= scl;
	y *= scl;
	z *= scl;
	return *this;
}

Vec3 Vec3::operator*(float scl) const
{
	Vec3 nVec = (*this) * scl;
	return nVec;
}

Vec3 Vec3::operator*=(float scl)
{
	return (*this) * scl;
}

// dot product
float Vec3::operator*(Vec3 rhs)
{
	return x * rhs.x + y * rhs.y + z * rhs.z;
}

Vec3 Vec3::operator/(float scl)
{
	x /= scl;
	y /= scl;
	z /= scl;
	return *this;
}



Vec3 Vec3::operator/(float scl) const
{
	Vec3 nVec = (*this) * scl;
	return nVec;
}

Vec3 Vec3::operator/=(float scl)
{
	return (*this) / scl;
}

float Vec3::GetLenghtSqr() const
{
	return x * x + y * y + z * z;
}

float Vec3::GetLenght() const
{
	return sqrt(this->GetLenghtSqr());
}

Vec3 Vec3::Normalize()
{

	if (this->GetLenght() != 0.f)
	{
		*this = (*this) / this->GetLenght();
	}
	return *this;
}

Vec3 Vec3::Normalize() const
{
	Vec3 normalize;
	if (this->GetLenght() != 0.f)
	{
		normalize = (*this) / this->GetLenght();
	}
	return normalize;
}






// Вектор направления
Vec3Dir::Vec3Dir(Vec3 endPoint, Vec3 startPoint)
	:
	endPoint(endPoint),
	startPoint(startPoint)
{
	xLen = endPoint.x - startPoint.x;
	yLen = endPoint.y - startPoint.y;
	zLen = endPoint.z - startPoint.z;
}

Vec3Dir Vec3Dir::operator*(float scl)
{
	endPoint.x *= scl;
	endPoint.y *= scl;
	endPoint.z *= scl;
	startPoint.x *= scl;
	startPoint.y *= scl;
	startPoint.z *= scl;
	xLen = endPoint.x - startPoint.x;
	yLen = endPoint.y - startPoint.y;
	zLen = endPoint.z - startPoint.z;
	return *this;
}

Vec3Dir Vec3Dir::operator*(float scl) const
{
	Vec3Dir nVecDir = (*this) * scl;
	return nVecDir;
}

Vec3Dir Vec3Dir::operator*=(float scl)
{
	return (*this) * scl;
}

Vec3Dir Vec3Dir::operator/(float scl)
{
	endPoint.x /= scl;
	endPoint.y /= scl;
	endPoint.z /= scl;
	startPoint.x /= scl;
	startPoint.y /= scl;
	startPoint.z /= scl;
	xLen = endPoint.x - startPoint.x;
	yLen = endPoint.y - startPoint.y;
	zLen = endPoint.z - startPoint.z;
	return *this;
}

Vec3Dir Vec3Dir::operator/(float scl) const
{
	Vec3Dir nVecDir = (*this) / scl;
	return nVecDir;
}

Vec3Dir Vec3Dir::operator/=(float scl)
{
	return (*this) / scl;
}

float Vec3Dir::GetLenghtSqr() const
{
	return xLen * xLen + yLen * yLen + zLen * zLen;
}

float Vec3Dir::GetLenght() const
{
	return sqrt(this->GetLenghtSqr());
}

Vec3Dir Vec3Dir::Normalize()
{
	if (this->GetLenght() != 0.f)
	{
		*this = (*this) / this->GetLenght();
	}
	return *this;
}

Vec3Dir Vec3Dir::Normalize() const
{
	Vec3Dir nVecNormalize;

	if (this->GetLenght() != 0.f)
	{
		nVecNormalize = (*this) / this->GetLenght();
	}
	return nVecNormalize;
}

