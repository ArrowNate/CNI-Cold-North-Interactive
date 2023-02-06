#ifndef __GAMEMANAGER_H
#define __GAMEMANAGER_H
#include <GLFW/glfw3.h>
#include "AssetManager.h"
#include "Graphics.h"
#include "ScreenManager.h"

class GameManager
{
private:
	static GameManager* sInstance;
	const int FRAME_RATE = 60;

	bool mQuit;
	Graphics* mGraphics;
	AssetManager* mAssetManager;
	Timer* mTimer;

	ScreenManager* mScreenManager;

public:
	static GameManager* Instance();
	
	static void Release();

	void Run();

	void Update();
	void LateUpdate();

	void Render();

	GameManager();
	~GameManager();
};

#endif