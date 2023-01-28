#ifndef __GAMEMANAGER_H
#define __GAMEMANAGER_H
#include <GLFW/glfw3.h>

class GameManager
{
private:
	static GameManager* sInstance;
	const int FRAME_RATE = 60;

	bool mQuit;

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