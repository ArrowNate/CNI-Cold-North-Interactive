#ifndef _GRAPHICS_H
#define _GRAPHICS_H

//#include "ScreenManager.h"
//#include "AudioManager.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "stb_image.h"
//#include "Font.h"
#include "Shader.h"
//#include "Texture.h"
#include <iostream>

class Graphics
{
private:
	//ScreenManager* m_pScreenManager;
	//AudioManager* m_pAudioManager;
		
	GLFWwindow* window;
	static Graphics* sInstance;
	//Font* m_pFontTest;

	//Texture* m_pBackground;
	//Texture* m_pTesting;
	//Texture* m_pMoose;

public:
	const unsigned int SCR_WIDTH = 1024;
	const unsigned int SCR_HEIGHT = 768;

public:
	Graphics();
	~Graphics();

	GLFWwindow* GetWindow();

	static Graphics* Instance();
	static void Release();
	static bool sInitialized;
	static bool Initialized();

	virtual bool Init();
};

#endif