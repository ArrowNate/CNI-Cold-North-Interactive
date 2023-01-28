#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H
#include <iostream>

class ScreenManager {
private:
	static ScreenManager* sInstance;

	enum Screens { Start, Play, Logo };
	Screens mCurrentScreen;
	int ScreenChoice;

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