#pragma once
class EditArea
{
private:
	HDC mDC;
	Graphics* mpGp = nullptr;

public:
	void Init();
	void Release();
};

