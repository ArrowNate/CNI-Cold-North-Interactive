#ifndef __GAMEMANAGER_H
#define __GAMEMANAGER_H
#include <GLFW/glfw3.h>
#include "AssetManager.h"
//#include "Graphics.h"
#include "ScreenManager.h"
#include "AudioManager.h"
//#include "InputManager.h"

class GameManager
{
private:
	static GameManager* sInstance;
	const int FRAME_RATE = 60;

	//bool mQuit;
	Graphics* m_pGraphics;
	AssetManager* m_pAssetManager;
	//GLFWwindow* window;
	//Timer* mTimer;

	ScreenManager* m_pScreenManager;
	StartScreen* m_pStartScreen;
	AudioManager* m_pAudioManager;
	InputManager* m_pInputManager;

public:
	static GameManager* Instance();
	
	static void Release();

	void Run();

	void Update();
	void LateUpdate();
	void Render();

	GameManager();
	~GameManager();

	void processInput(GLFWwindow* window);

	//GLFWwindow* GetWindow();
};

#endif