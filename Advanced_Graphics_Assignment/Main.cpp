#include <iostream>
#include "GameManager.h"

int main() 
{
	GameManager* game = GameManager::Instance();

	game->Run();

	Timer::Instance()->Update();

	GameManager::Release();

	game = nullptr;

	return 0;
}