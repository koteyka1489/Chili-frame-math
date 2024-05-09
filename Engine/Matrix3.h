#pragma once
#include "Vec2.h"


class Matrix3
{
public:
	Matrix3();
	Matrix3(float c00, float c01, float c02, float c10, float c11, float c12, float c20, float c21, float c22);
	Vec2 operator* (Vec2 rhs);
	Matrix3 operator* (Matrix3 rhs) const;
	Matrix3 ScaleMatrix3(float scale);
	Matrix3 RotateMatrix3(float theta);
	Matrix3 TranslateMatrix3(Vec2 offset);

public:
	//      [rows][col]
	float cells[3][3];
};

