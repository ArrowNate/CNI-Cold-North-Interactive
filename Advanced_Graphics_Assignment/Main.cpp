#include <iostream>
#include "GameManager.h"

int main() 
{
	/*AudioManager* audio = AudioManager::Instance();

	AudioManager::Release();

	audio = nullptr;*/

	GameManager* game = GameManager::Instance();

	game->Run();

	GameManager::Release();

	game = nullptr;

	return 0;
}