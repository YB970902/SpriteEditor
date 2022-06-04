#include "stdafx.h"
#include "WindowManager.h"

SpriteEditor* WindowManager::mpSpriteEditor = nullptr;

void WindowManager::Init(LPWSTR title)
{
	mpTitle = title;
	mpSpriteEditor = new SpriteEditor();
	mpSpriteEditor->Init();
	createWindowClass();
}

void WindowManager::Release()
{
	SAFE_RELEASE(mpSpriteEditor);
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
	}
}

// �⺻���� ���ۿ� ���� ����
LRESULT WindowManager::WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
	case WM_MOUSEWHEEL:
		g_wheel = GET_WHEEL_DELTA_WPARAM(wParam) / WHEEL_DELTA;
		break;
	case WM_LBUTTONDOWN:
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return mpSpriteEditor->WndProc(hWnd, iMessage, wParam, lParam);
}

void WindowManager::createWindowClass()
{
	// ������ Ŭ���� ���� �� ���
	WNDCLASS wndClass;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hInstance = g_hInstance;
	wndClass.lpfnWndProc = WndProc;
	wndClass.lpszClassName = mpTitle;
	wndClass.lpszMenuName = mpTitle;
	wndClass.style = CS_VREDRAW | CS_HREDRAW;
	RegisterClass(&wndClass);

	// ������ ����
	g_hWnd = CreateWindowEx(
		WS_EX_APPWINDOW,
		mpTitle,
		mpTitle,
		WS_OVERLAPPEDWINDOW,
		WINDOW_POS_X,
		WINDOW_POS_Y,
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
		nullptr,
		nullptr,
		g_hInstance,
		nullptr);

	// �����찡 ���̵��� ����
	ShowWindow(g_hWnd, g_nCmdShow);
}
