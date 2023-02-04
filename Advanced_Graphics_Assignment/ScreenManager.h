#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H
#include <iostream>
#include "PlayScreen.h"
#include "StartScreen.h"
//#include "Graphics.h"

class ScreenManager
{
private:
	static ScreenManager* sInstance;

	enum Screens { Start, Play};
	Screens mCurrentScreen;
	//GLFWwindow* window;
	PlayScreen* m_pPlayScreen;
	StartScreen* m_pStartScreen;

	int ScreenChoice;

private:
	ScreenManager();
	~ScreenManager();

public:
	static ScreenManager* Instance();
	static void Release();
	
	static void Init();
	void Update();
	void Render();

};

#endif // !SCREENMANAGER_H