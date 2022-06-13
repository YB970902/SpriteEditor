#pragma once

#include <iostream>
#include <filesystem>
#include <gdiplus.h>				// GDI+�� ����ϱ� ���� �������
#pragma comment(lib, "gdiplus")		// GDI+�� ����ϱ� ���� ���̺귯�� ����

#include "rapidjson/document.h"

using namespace Gdiplus;
using namespace std;
using namespace std::filesystem;

#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif