#include "../PCH/stdafx.h"
#include "WindowManager.h"

void WindowManager::Init(LPWSTR title)
{
	mpTitle = title;
	createWindowClass();
	renderWindow();
}

void WindowManager::Release()
{
	//SAFE_RELEASE(mpGameRoot);
}

void WindowManager::Run()
{
	while (true)
	{
		if (PeekMessage(&mMessage, 0, 0, 0, PM_REMOVE))
		{
			if (mMessage.message == WM_QUIT) { break; }

			TranslateMessage(&mMessage);
			DispatchMessage(&mMessage);
		}
		else
		{
			//mpGameRoot->Run();
		}
	}
}

LRESULT WindowManager::WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
	case WM_MOUSEWHEEL:
		g_wheel = GET_WHEEL_DELTA_WPARAM(wParam) / WHEEL_DELTA;
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}

void WindowManager::createWindowClass()
{
	WNDCLASS wndClass;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hInstance = g_hInstance;
	//wndClass.lpfnWndProc = WndProc;
	wndClass.lpszClassName = mpTitle;
	wndClass.lpszMenuName = mpTitle;
	wndClass.style = CS_VREDRAW | CS_HREDRAW;
	RegisterClass(&wndClass);

	ShowCursor(false);

	g_hWnd = CreateWindowEx(
		WS_EX_APPWINDOW,
		mpTitle,
		mpTitle,
		WS_POPUP,
		0,
		0,
		GetSystemMetrics(SM_CXSCREEN),
		GetSystemMetrics(SM_CYSCREEN),
		nullptr,
		nullptr,
		g_hInstance,
		nullptr);
}

void WindowManager::renderWindow()
{
	ShowWindow(g_hWnd, g_nCmdShow);

	//mpGameRoot = new GameRoot();
	//mpGameRoot->Init();
}
