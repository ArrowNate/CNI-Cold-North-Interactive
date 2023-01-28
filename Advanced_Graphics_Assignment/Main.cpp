#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "Graphics.h"



int main() 
{
	
	Graphics* graphics = Graphics::Instance();

	graphics->Init();

	Graphics::Release();

	graphics = nullptr;

	return 0;
}