#include "XMath.h"
#include <cmath>


Matrix3::Matrix3()
{
    cells[0][0] = 1.0f;
    cells[0][1] = 0.0f;
    cells[0][2] = 0.0f;
    cells[1][0] = 0.0f;
    cells[1][1] = 1.0f;
    cells[1][2] = 0.0f;
    cells[2][0] = 0.0f;
    cells[2][1] = 0.0f;
    cells[2][2] = 1.0f;
}

Matrix3::Matrix3(float c00, float c01, float c02, float c10, float c11, float c12, float c20, float c21, float c22)
{
    cells[0][0] = c00;
    cells[0][1] = c01;
    cells[0][2] = c02;
    cells[1][0] = c10;
    cells[1][1] = c11;
    cells[1][2] = c12;
    cells[2][0] = c20;
    cells[2][1] = c21;
    cells[2][2] = c22;
}

Vec2 Matrix3::operator*(Vec2 rhs)
{
    Vec2 outV;
    outV.x = cells[0][0] * rhs.x + cells[1][0] * rhs.y + cells[2][0] * rhs.w;
    outV.y = cells[0][1] * rhs.x + cells[1][1] * rhs.y + cells[2][1] * rhs.w;
    outV.w = cells[0][2] * rhs.x + cells[1][2] * rhs.y + cells[2][2] * rhs.w;
    return outV;
}

Vec3 Matrix3::operator*(Vec3 rhs)
{
    Vec3 outV;
    outV.x = cells[0][0] * rhs.x + cells[1][0] * rhs.y + cells[2][0] * rhs.z;
    outV.y = cells[0][1] * rhs.x + cells[1][1] * rhs.y + cells[2][1] * rhs.z;
    outV.z = cells[0][2] * rhs.x + cells[1][2] * rhs.y + cells[2][2] * rhs.z;
    return outV;
}

Matrix3 Matrix3::operator*(Matrix3 rhs) const
{
    Matrix3 outM;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            outM.cells[i][j] = 0.f;
            for (int k = 0; k < 3; k++)
            {
                outM.cells[i][j] += cells[i][k] * rhs.cells[k][j];
            }
        }
    }

    return outM;
}

Matrix3 Matrix3::ScaleMatrix3(float scale)
{
    return
    { scale,   0.f,     0.f,
      0.f,     scale,   0.f,
      0.f,     0.f,     1.f };
}

Matrix3 Matrix3::RotateMatrix3_Z(float theta)
{
    float cosTheta = std::cos(theta);
    float sinTheta = std::sin(theta);

    return
    {  cosTheta, sinTheta,   0.f,
      -sinTheta, cosTheta,   0.f,
       0.f,      0.f,        1.f };
}

Matrix3 Matrix3::RotateMatrix3_Y(float theta)
{
    float cosTheta = std::cos(theta);
    float sinTheta = std::sin(theta);

    return
    { cosTheta,  0.f,   -sinTheta,
      0.f,       1.f,   0.f,
      sinTheta,  0.f,   cosTheta };
}

Matrix3 Matrix3::RotateMatrix3_Y_Inverse(float theta)
{
    float cosTheta = std::cos(theta);
    float sinTheta = std::sin(theta);

    return
    { cosTheta,  0.f,   sinTheta,
      0.f,       1.f,   0.f,
      -sinTheta,  0.f,   cosTheta };
}

Matrix3 Matrix3::RotateMatrix3_X(float theta)
{
    float cosTheta = std::cos(theta);
    float sinTheta = std::sin(theta);

    return
    { 1.f,     0.f,        0.f,
      0.f,     cosTheta,   sinTheta,
      0.f,     -sinTheta,  cosTheta };
}

Matrix3 Matrix3::TranslateMatrix3(Vec2 offset)
{
    return
    { 1.f,     0.f,     offset.x,
      0.f,     1.f,     offset.y,
      0.f,     0.f,     1.f };
}

Matrix3 Matrix3::GetModelMarixTRS(Matrix3 Rotate, Matrix3 Scale, Matrix3 Translate)
{
    Matrix3 modelMatrix = Translate * Scale * Rotate;
    return modelMatrix;
}



