
#include "Graphics.h"

using OpenGLFramework::Graphics;

int main() 
{
	

	Graphics* graphics = Graphics::Instance();

	graphics->Init();

	Graphics::Release();

	graphics = nullptr;

	return 0;
}