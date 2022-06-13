#pragma once
class DrawManager
{
private:
	bool isInit = false;

	static DrawManager* instance;

	DrawManager() = default;
	~DrawManager() = default;

	HDC backBuffer = nullptr;
	HDC mainDC = nullptr;

public:
	static DrawManager* GetInstance();

	void Init();
	void Release();
	void Render();
};

DrawManager* DrawManager::instance = nullptr;