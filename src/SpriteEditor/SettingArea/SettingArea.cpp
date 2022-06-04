#include "stdafx.h"
#include "SettingArea.h"

void SettingArea::Init()
{
	mDC = GetDC(g_hWnd);
}

void SettingArea::Release()
{
	ReleaseDC(g_hWnd, mDC);
}
