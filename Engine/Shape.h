#pragma once
#include <vector>
#include "Vec2.h"
#include "Graphics.h"
#include "MainWindow.h"
#include "Stick.h"
#include "XMath.h"
#include "Sound.h"



class Shape
{
public:
	Shape();
	Shape(float x, float y, int nVert, float radius, Color clr);
	Shape& operator=(const Shape& rhs);
	Shape(const Shape& rhs);
	void Update(MainWindow& wnd);
	void Draw(Graphics& gfx, Vec2 cameraOfsset, float scaleCameraMod, float thetaAngleCameraRotate, Vec2 centerRotation);

	void SetCenter();
	void UpdateSpeed(Vec2 dir);
	void Move();
	void MoveCamera(Vec2 dir);
	void ScaleFromCenterShape(MainWindow& wnd, bool dir);
	void CheckCollision (Stick stick);
	Vec2 GetCenter();
	float GetRadius();
	Vec2 GetSpeed();
	void SetSpeed(Vec2 speed_in);
	bool GetRebounded();
	void SetRebounded(bool reb);
	void Rotate(float angle);


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

