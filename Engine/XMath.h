#pragma once
#include <cmath>
#include "Vec2.h"
#include "Vec3.h"

constexpr double PI = 3.14159265358;

//static float DistancePointLine(Point p0, Point p1, Point q)
//{
//	float a = p0.y - p1.y;
//	float b = p1.x - p0.x;
//	float c = p0.x * p1.y - p1.x * p0.y;
//
//	return std::abs(a * q.x + b * q.y + c) / std::sqrt(a * a + b * b);
//
//}


class Matrix3
{
public:
	Matrix3();
	Matrix3(float c00, float c01, float c02, float c10, float c11, float c12, float c20, float c21, float c22);
	Vec2 operator* (Vec2 rhs);
	Vec3 operator* (Vec3 rhs);
	Matrix3 operator* (Matrix3 rhs) const;
	Matrix3 ScaleMatrix3(float scale);
	Matrix3 RotateMatrix3_Z(float theta);
	Matrix3 RotateMatrix3_Y(float theta);
	Matrix3 RotateMatrix3_X(float theta);
	Matrix3 TranslateMatrix3(Vec2 offset);
	Matrix3 GetModelMarixTRS(Matrix3 Scale, Matrix3 Rotate, Matrix3 Translate);

public:
	//      [rows][col]
	float cells[3][3];
};


