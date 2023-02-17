#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H
#include <iostream>
#include <vector>
#include "StartScreen.h"
#include "PlayScreen.h"
#include "Credits.h"
#include "SplashScreen.h"
#include "LevelManager.h"
#include "GameOverScreen.h"
//#include "Graphics.h"

class ScreenManager
{
private:
	static ScreenManager* sInstance;

	enum Screens { Credit, Play, Start, Splash, GameOver };
	Screens mCurrentScreen;
	//GLFWwindow* window;
	StartScreen* m_pStartScreen;
	LevelManager* m_pLevelManager;
	GameOverScreen* m_pGameOverScreen;
	//PlayScreen* m_pPlayScreen;

	Credits* m_pCredits;
	SplashScreen* m_pSplashScreen;
	std::vector<GameEntity*>Screens;

	int ScreenChoice;

private:
	ScreenManager();
	~ScreenManager();

public:
	static ScreenManager* Instance();
	static void Release();
	
	static void Init();
	void Update();
	void LateUpdate();
	void Render();

};

#endif // !SCREENMANAGER_H