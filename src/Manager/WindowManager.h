#pragma once
#include "SpriteEditor/SpriteEditor.h"

class WindowManager
{
private:
	MSG mMessage;
	WNDCLASS mWndClass;
	LPWSTR mpTitle;

	static SpriteEditor* mpSpriteEditor;
public:
	void Init(LPWSTR title);
	void Release();

	void Run();

	MSG GetWindowMsg() { return mMessage; }

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

private:
	void createWindowClass();
};