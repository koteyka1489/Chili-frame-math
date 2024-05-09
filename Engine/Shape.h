#pragma once
#include <vector>
#include "Vec2.h"
#include "Graphics.h"
#include "MainWindow.h"
#include "Stick.h"
#include "XMath.h"
#include "Sound.h"
#include "Drawable.h"



class Shape
{
public:
	Shape();
	Shape(float x, float y, int nVert, float radius, Color clr);
	Shape& operator=(const Shape& rhs);
	Shape(const Shape& rhs);

	

	void SetCenter();
	void UpdateSpeed(Vec2 dir);
	void Move();
	void CheckCollision (Stick stick);
	Vec2 GetCenter();
	float GetRadius();
	Vec2 GetSpeed();
	void SetSpeed(Vec2 speed_in);
	bool GetRebounded();
	void SetRebounded(bool reb);
	void SetPointsOfset(Vec2 ofset);
	void SetPointsScale(float scl);
	void SetRotation(float theta, Vec2 centerRot);
	std::vector<Vec2> GetPoints();
	Color GetColor();

private:
	std::vector<Vec2> points;
	Color clr = Colors::White;
	static  constexpr int nVert = 5;
	Vec2 center = { 0.0f, 0.0f };
	float radius = 0.0f;
	float speedSqale = 5.0f;
	float sizeScale = 0.1f;
	Vec2 speedVec = { -2.5f, -5.f };
	bool rebounded = false;
	Sound collideSound = Sound(L"Sounds//fart1.wav");
};

