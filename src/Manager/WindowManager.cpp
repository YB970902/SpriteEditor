#include "stdafx.h"
#include "WindowManager.h"

ULONG_PTR WindowManager::mGpToken = 0;
SpriteEditor* WindowManager::mpSpriteEditor = nullptr;

void WindowManager::Init(LPWSTR title)
{
	mpTitle = title;
	mpSpriteEditor = new SpriteEditor();
	initGdiplus();
	createWindowClass();
	mpSpriteEditor->Init();
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

// 기본적인 동작에 대한 설정
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
		GdiplusShutdown(mGpToken);
		PostQuitMessage(0);
		break;
	}

	return mpSpriteEditor->WndProc(hWnd, iMessage, wParam, lParam);
}

void WindowManager::initGdiplus()
{
	GdiplusStartupInput gpsi;	// GDI+의 처리 방식에 추가적인 옵션을 설정하는 변수
	// 잘못된 옵션이 설정되거나 그래픽 장치가 GDI+를 지원하지 못하면
	// GdiplusStartup 함수가 실패할수도 있음
	assert(GdiplusStartup(&mGpToken, &gpsi, NULL) == Ok, "This device not support gdiplus!");
}

void WindowManager::createWindowClass()
{
	// 윈도우 클래스 생성 및 등록
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

	// 윈도우 생성
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

	// 윈도우가 보이도록 설정
	ShowWindow(g_hWnd, g_nCmdShow);

	RECT rc = { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT };

	// border를 계산한 윈도우의 크기 반환
	AdjustWindowRectEx(&rc, WS_OVERLAPPEDWINDOW, false, 0);
	// 윈도우 크기 재설정
	SetWindowPos(g_hWnd, HWND_TOP, WINDOW_POS_X, WINDOW_POS_Y, rc.right - rc.left, rc.bottom - rc.top, 0);
}
