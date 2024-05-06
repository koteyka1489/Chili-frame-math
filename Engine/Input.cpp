#include "Input.h"


// ВВОД С МЫШИ
MouseInput::MouseInput(MainWindow& wnd)
	:
	wnd(wnd)
{
}

void MouseInput::Execute()
{
	// считываем нажатие кнопок мыши
	if (wnd.mouse.LeftIsPressed()) { leftIsPressed = true; }
	if (wnd.mouse.RightIsPressed()) { rightIsPressed = true; }

	// считываем вращение колеса мыши
	const auto e = wnd.mouse.Read();
	if (e.GetType() == Mouse::Event::Type::WheelUp)	{wheelUp = true; }
	if (e.GetType() == Mouse::Event::Type::WheelDown) { wheelDown = true; }

	// считываем позицию мыши
	xPosMouse = wnd.mouse.GetPosX();
	yPosMouse = wnd.mouse.GetPosY();
}

bool MouseInput::GetWheelUp()
{
	return wheelUp;
}

bool MouseInput::GetWheelDown()
{
	return wheelDown;
}

bool MouseInput::GetLeftIsPressed()
{
	return leftIsPressed;
}

bool MouseInput::GetRightIsPressed()
{
	return rightIsPressed;
}

float MouseInput::GetPosX()
{
	return xPosMouse;
}

float MouseInput::GetPosY()
{
	return yPosMouse;
}

Vec2 MouseInput::GetMousePos()
{
	return Vec2(GetPosX(), GetPosY());
}






// ВВОД С КЛАВИАТУРЫ

KeyboardInput::KeyboardInput(MainWindow& wnd)
	:
	wnd(wnd)
{}


// обработка ввода с клавиатуры
void KeyboardInput::Execute()
{
	if (wnd.kbd.KeyIsPressed(VK_LEFT)) { leftIsPressed = true; }
	if (wnd.kbd.KeyIsPressed(VK_RIGHT)) { rightIsPressed = true; }
	if (wnd.kbd.KeyIsPressed(VK_UP)) { upIsPressed = true; }
	if (wnd.kbd.KeyIsPressed(VK_DOWN)) { downIsPressed = true; }
	if (wnd.kbd.KeyIsPressed('Q')) { qIsPressed = true; }
	if (wnd.kbd.KeyIsPressed('E')) { eIsPressed = true; }
}

bool KeyboardInput::LefttIsPressed()
{
	return leftIsPressed;
}

bool KeyboardInput::RightIsPressed()
{
	return rightIsPressed;
}

bool KeyboardInput::UpIsPressed()
{
	return upIsPressed;
}

bool KeyboardInput::DownIsPressed()
{
	return downIsPressed;
}

bool KeyboardInput::EIsPresses()
{
	return eIsPressed;
}

bool KeyboardInput::QIsPressed()
{
	return qIsPressed;
}
