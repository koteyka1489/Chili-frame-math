#pragma once
#include "MainWindow.h"
#include "Vec2.h"

class Input
{
public:
	virtual ~Input() {};
	virtual  void Execute() = 0;

};


// класс ввода с мыши
class MouseInput : public Input
{
public:
	MouseInput(MainWindow& wnd);
	void Execute();
	bool GetWheelUp();
	bool GetWheelDown();
	bool GetLeftIsPressed();
	bool GetRightIsPressed();
	float GetPosX();
	float GetPosY();
	Vec2 GetMousePos();


private:
	MainWindow& wnd;
	bool wheelUp = false;
	bool wheelDown = false;
	bool leftIsPressed = false;
	bool rightIsPressed = false;
	float xPosMouse = 0.f;
	float yPosMouse = 0.f;
	
};

// класс ввода с клавиатуры
class KeyboardInput : public Input
{
public:
	KeyboardInput(MainWindow& wnd);
	void Execute();
	bool LefttIsPressed();
	bool RightIsPressed();
	bool UpIsPressed();
	bool DownIsPressed();
	bool EIsPresses();
	bool QIsPressed();
	bool WIsPressed();
	bool AIsPressed();
	bool SIsPressed();
	bool DIsPressed();

private:
	MainWindow& wnd;
	bool leftIsPressed = false;
	bool rightIsPressed = false;
	bool upIsPressed = false;
	bool downIsPressed = false;
	bool eIsPressed = false;
	bool qIsPressed = false;
	bool W_IsPressed = false;
	bool A_IsPressed = false;
	bool S_IsPressed = false;
	bool D_IsPressed = false;
};

