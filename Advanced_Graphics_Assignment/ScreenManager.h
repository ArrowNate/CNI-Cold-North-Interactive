#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H
#include <iostream>
#include "PlayScreen.h"
#include "StartScreen.h"


class ScreenManager {
private:
	static ScreenManager* sInstance;

	enum Screens { Start, Play, Logo };
	Screens mCurrentScreen;
	int ScreenChoice;
	PlayScreen* m_pPlayScreen;
	StartScreen* m_pStartScreen;

public:
	static ScreenManager* Instance();
	static void Release();

	void Update();
	void Render();

private:
	ScreenManager();
	~ScreenManager();
};

#endif // !SCREENMANAGER_H