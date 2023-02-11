#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H
#include <iostream>
#include <vector>
#include "StartScreen.h"
#include "PlayScreen.h"
#include "SplashScreen.h"
#include "Credits.h"
//#include "Graphics.h"

class ScreenManager
{
private:
	static ScreenManager* sInstance;

	enum Screens { Credit, Play, Start, Splash };
	Screens mCurrentScreen;
	//GLFWwindow* window;
	StartScreen* m_pStartScreen;
	PlayScreen* m_pPlayScreen;
	SplashScreen* m_pSplashScreen;
	Credits* m_pCredits;
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
	void Render();

};

#endif // !SCREENMANAGER_H