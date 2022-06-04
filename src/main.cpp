#include "stdafx.h"
#include "../Manager/WindowManager.h"
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC

int APIENTRY wWinMain(HINSTANCE _hInstance, HINSTANCE _hPrevInstance, LPWSTR _lpszCmdParam, int nCmdShow)
{
#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	g_hInstance = _hInstance;
	g_nCmdShow = nCmdShow;

	WindowManager windowMgr;
	windowMgr.Init(WINDOW_TITLE);

	windowMgr.Run();

	windowMgr.Release();

	return windowMgr.GetWindowMsg().wParam;
}