#ifndef _GRAPHICS_H
#define _GRAPHICS_H


#include <GLFW/glfw3.h>
#include <iostream>
#include "stb_image.h"
#include "Font.h"

class Graphics
{
		
	//GLFWwindow* window;
	static Graphics* sInstance;

	const unsigned int SCR_WIDTH = 800;
	const unsigned int SCR_HEIGHT = 600;

public:
	//Graphics();
	//~Graphics();

	static Graphics* Instance();
	static void Release();
	static bool sInitialized;
	static bool Initialized();


		

	virtual bool Init();
};



#endif