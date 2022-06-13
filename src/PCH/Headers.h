#pragma once

#include <iostream>
#include <filesystem>
#include <gdiplus.h>				// GDI+를 사용하기 위한 헤더파일
#pragma comment(lib, "gdiplus")		// GDI+를 사용하기 위한 라이브러리 파일

#include "rapidjson/document.h"

using namespace Gdiplus;
using namespace std;
using namespace std::filesystem;

#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif