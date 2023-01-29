#ifndef _GRAPHICS_H
#define _GRAPHICS_H


#include <GLFW/glfw3.h>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "stb_image.h"
#include "Font.h"
#include "Shader.h"

class Graphics
{
		
	//GLFWwindow* window;
	static Graphics* sInstance;
	Font* m_pFontTest;

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