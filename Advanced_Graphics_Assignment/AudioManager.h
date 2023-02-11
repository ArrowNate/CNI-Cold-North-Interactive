#ifndef _AUDIOMANAGER_H
#define _AUDIOMANAGER_H
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <irrKlang/irrKlang.h>
#include <GLFW/glfw3.h>

using namespace irrklang;

class AudioManager
{
private:
	ISoundEngine* m_pSoundEngine;


public:
	static AudioManager* sInstance;
	static AudioManager* Instance();
	static void Release();
	//static bool sInitialized;
	static bool Initialized();

	//virtual bool Init();

public:
	AudioManager();
	~AudioManager();

	void PlayMusic();
	void PlayMusic2(const char filepath[50], bool loop = true);
	void PlayMusic3D(const char filepath[50], float x, float y, float z, bool loop = true);
	void PauseMusic();
	void PlaySFX();
	void PlayIntro();
	void PauseIntro();
	//void processInput(GLFWwindow* window);
};

#endif // !_AUDIOMANAGER_H