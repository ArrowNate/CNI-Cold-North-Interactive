<<<<<<< Updated upstream
=======
#include <GLFW/glfw3.h>
#include <glad/glad.h>
>>>>>>> Stashed changes

#include "Graphics.h"



int main() 
{
	
	Graphics* graphics = Graphics::Instance();

	graphics->Init();

	Graphics::Release();

	graphics = nullptr;

	return 0;
}