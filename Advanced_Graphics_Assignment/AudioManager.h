#ifndef _AUDIOMANAGER_H
#define _AUDIOMANAGER_H
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <irrKlang/irrKlang.h>

using namespace irrklang;

class AudioManager
{
public:
	ISoundEngine* SoundEngine = createIrrKlangDevice();

//private:
//	static AudioManager* sInstance;
//
//public:
//	static AudioManager* Instance();
//	static void Release();

private:
	AudioManager();
	~AudioManager();
};

#endif // !_AUDIOMANAGER_H