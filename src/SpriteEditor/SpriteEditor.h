#pragma once

class EditArea;
class SettingArea;
class SpriteEditor
{
private:
	EditArea* mpEditArea = nullptr;
	SettingArea* mpSettingArea = nullptr;

public:
	void Init();
	void Release();

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
private:
};