#include <iostream>
#include "AudioManager.h"
#include "Graphics.h"

int main() 
{
	/*AudioManager* audio = AudioManager::Instance();

	AudioManager::Release();

	audio = nullptr;*/

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	Graphics* graphics = Graphics::Instance();

	graphics->Init();

	Graphics::Release();

	graphics = nullptr;

	return 0;
}