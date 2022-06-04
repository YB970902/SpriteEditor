#pragma once

class EditArea;
class SettingArea;
class SpriteEditor
{
public:
	void Init();
	void Release();

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
private:
};