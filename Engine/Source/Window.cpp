#include "Window.h"
#include <memory>

Window* window;
#define WINDOW_GET_X_LPARAM(lp) ((int)(short)LOWORD(lp))
#define WINDOW_GET_Y_LPARAM(lp) ((int)(short)HIWORD(lp))

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	}
	case WM_CLOSE:
	{
		PostQuitMessage(0);
		exit(0);
		return 0;
	}
	case WM_KEYDOWN:
	{
		window->inputs.keys[(unsigned int)wParam] = true;
		return 0;
	}
	case WM_KEYUP:
	{
		window->inputs.keys[(unsigned int)wParam] = false;
		return 0;
	}
	case WM_LBUTTONDOWN:
	{
		window->inputs.UpdateMouse(WINDOW_GET_X_LPARAM(lParam), WINDOW_GET_Y_LPARAM(lParam));
		window->inputs.mouseButtons[0] = true;
		return 0;
	}
	case WM_LBUTTONUP:
	{
		window->inputs.UpdateMouse(WINDOW_GET_X_LPARAM(lParam), WINDOW_GET_Y_LPARAM(lParam));
		window->inputs.mouseButtons[0] = false;
		return 0;
	}
	case WM_MOUSEMOVE:
	{
		window->inputs.UpdateMouse(WINDOW_GET_X_LPARAM(lParam), WINDOW_GET_Y_LPARAM(lParam));
		return 0;
	}
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
}

#pragma region Window

void Window::Create(unsigned int _width, unsigned int _height, std::string _name, bool _fullScreen, unsigned int _x, unsigned int _y)
{
	name = _name;
	width = _width;
	height = _height;

	style = WS_OVERLAPPEDWINDOW | WS_VISIBLE;
	hinstance = GetModuleHandle(NULL);

	WNDCLASSEX wc{ 0 };
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hinstance;

	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wc.hIconSm = NULL; // wc.hIcon;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);

	wc.hbrBackground = NULL; // (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.lpszMenuName = NULL;
	std::wstring wname = std::wstring(name.begin(), name.end());
	wc.lpszClassName = wname.c_str();
	wc.cbSize = sizeof(WNDCLASSEX);
	RegisterClassEx(&wc);

	// create window
	hwnd = CreateWindowEx(WS_EX_APPWINDOW, wname.c_str(), wname.c_str(), style, _x, _y, width, height, NULL, NULL, hinstance, this);

	// set default values for inputs
	inputs.Reset();

	// set window pointer
	window = this;

	// initialize DriectX driver
	dxDriver.Init(width, height, hwnd, _fullScreen);
}

void Window::Update() {

	inputs.Update();

	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));
	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

DXCore& Window::GetDevice() { return dxDriver; }

void Window::Clear() { dxDriver.Clear(); }
void Window::Present() { dxDriver.Present(); }

#pragma endregion

#pragma region Inputs

void Inputs::Reset()
{
	memset(keys, 0, 256 * sizeof(bool));
	memset(mouseButtons, 0, 3 * sizeof(bool));
	mousePos = mouseDelta = Vec2(0, 0);
}

void Inputs::Update() { mouseDelta = Vec2(0, 0); }

void Inputs::UpdateMouse(int _x, int _y)
{
	Vec2 newPos(_x, _y);
	mouseDelta = newPos - mousePos;
	mousePos = newPos;
}

Vec2 Inputs::GetAxis()
{
	Vec2 axis;

	if (KeyPressed('W'))
		axis.y = 1;
	else if (KeyPressed('S'))
		axis.y = -1;

	if (KeyPressed('D'))
		axis.x = 1;
	else if (KeyPressed('A'))
		axis.x = -1;

	return axis.Normalize();
}

Vec2 Inputs::GetAxis2()
{
	Vec2 axis;

	if (KeyPressed(VK_UP))
		axis.y = 1;
	else if (KeyPressed(VK_DOWN))
		axis.y = -1;

	if (KeyPressed(VK_RIGHT))
		axis.x = 1;
	else if (KeyPressed(VK_LEFT))
		axis.x = -1;

	return axis.Normalize();
}

bool Inputs::KeyPressed(int key) const { return keys[key]; }

Vec2 Inputs::MousePos() const { return mousePos; }

Vec2 Inputs::MouseDelta() const { return mouseDelta; }

#pragma endregion