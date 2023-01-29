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
	ISoundEngine* SoundEngine;

private:
	static AudioManager* sInstance;
	static AudioManager* Instance();
	static void Release();
	static bool sInitialized;
	static bool Initialized();

	//virtual bool Init();

public:
	AudioManager();
	~AudioManager();
};

#endif // !_AUDIOMANAGER_H