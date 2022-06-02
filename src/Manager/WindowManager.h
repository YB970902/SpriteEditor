#pragma once
class WindowManager
{
private:
	MSG mMessage;
	WNDCLASS mWndClass;
	LPWSTR mpTitle;
public:
	void Init(LPWSTR title);
	void Release();

	void Run();

	MSG GetWindowMsg() { return mMessage; }

	LRESULT WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

private:
	void createWindowClass();
	void renderWindow();
};