#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "stb_image.h"


class Graphics
{
		
	//GLFWwindow* window;
	static Graphics* sInstance;

	const unsigned int SCR_WIDTH = 1000;
	const unsigned int SCR_HEIGHT = 1008;

public:
	//Graphics();
	//~Graphics();

	static Graphics* Instance();
	static void Release();
	static bool sInitialized;
	static bool Initialized();


		

	virtual bool Init();
};



