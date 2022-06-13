#include "stdafx.h"
#include "DrawManager.h"

DrawManager* DrawManager::GetInstance()
{
	if (!instance)
	{
		instance = new DrawManager();
		instance->Init();
	}
	return instance;
}

void DrawManager::Init()
{
	if (isInit) { return; }
	
	isInit = true;


}

void DrawManager::Release()
{
}

void DrawManager::Render()
{
}
