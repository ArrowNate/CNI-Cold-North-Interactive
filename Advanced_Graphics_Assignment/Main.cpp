#include <iostream>
#include "AudioManager.h"
#include "Graphics.h"

using namespace irrklang;

int main() 
{
	AudioManager audioManager();

	Graphics* graphics = Graphics::Instance();

	graphics->Init();

	Graphics::Release();

	graphics = nullptr;

	return 0;
}