#ifndef __GAMEMANAGER_H
#define __GAMEMANAGER_H
#include <GLFW/glfw3.h>
#include "AssetManager.h"
#include "Graphics.h"

class GameManager
{
private:
	static GameManager* sInstance;
	const int FRAME_RATE = 60;

	bool mQuit;

public:
	static GameManager* Instance();
	Graphics* mGraphics;
	AssetManager* mAssetManager;
	static void Release();
};

#endif