#pragma once

#include <gdiplus.h>				// GDI+�� ����ϱ� ���� �������
#pragma comment(lib, "gdiplus")		// GDI+�� ����ϱ� ���� ���̺귯�� ����

#include "rapidjson/document.h"

using namespace Gdiplus;

#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif