#pragma once


// Window Default Settings

#define WINDOW_POS_X 100
#define WINDOW_POS_Y 100
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

#define WINDOW_TITLE (LPWSTR)TEXT("Sprite Editor")


#define SAFE_RELEASE(p) if(p) { p->Release(); delete p; p = nullptr; }
#define SAFE_DELETE(p) if(p) { delete p; p = nullptr; }
