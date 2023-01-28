#include <GLFW/glfw3.h>
#include <iostream>
#include <irrKlang/irrKlang.h>
#include "Graphics.h"

using namespace irrklang;

int main() 
{
	Graphics* graphics = Graphics::Instance();

	graphics->Init();

	Graphics::Release();

	graphics = nullptr;

	return 0;
}