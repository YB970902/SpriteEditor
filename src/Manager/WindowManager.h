#pragma once
#include "SpriteEditor/SpriteEditor.h"

class WindowManager
{
private:
	MSG mMessage;
	WNDCLASS mWndClass;
	LPWSTR mpTitle;
	static ULONG_PTR mGpToken; // GDI+의 사용을 위한 변수

	static SpriteEditor* mpSpriteEditor;
public:
	void Init(LPWSTR title);
	void Release();

	void Run();

	MSG GetWindowMsg() { return mMessage; }

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

private:
	void initGdiplus();
	void createWindowClass();
};