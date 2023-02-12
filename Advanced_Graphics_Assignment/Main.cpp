#include <iostream>
#include "GameManager.h"

int main() 
{
	GameManager* game = GameManager::Instance();

	game->Run();

	GameManager::Release();

	game = nullptr;

	return 0;
}