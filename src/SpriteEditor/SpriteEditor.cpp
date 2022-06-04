#include "stdafx.h"
#include "SpriteEditor.h"
#include "EditArea/EditArea.h"
#include "SettingArea/SettingArea.h"

void SpriteEditor::Init()
{
	mpEditArea = new EditArea();
	mpEditArea->Init();
	mpSettingArea = new SettingArea();
	mpSettingArea->Init();
}

void SpriteEditor::Release()
{
	SAFE_RELEASE(mpEditArea);
	SAFE_RELEASE(mpSettingArea);
}

LRESULT SpriteEditor::WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}
