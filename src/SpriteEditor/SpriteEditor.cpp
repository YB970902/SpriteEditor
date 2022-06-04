#include "stdafx.h"
#include "SpriteEditor.h"
#include "EditArea/EditArea.h"
#include "SettingArea/SettingArea.h"

void SpriteEditor::Init()
{
}

void SpriteEditor::Release()
{
}

LRESULT SpriteEditor::WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}
