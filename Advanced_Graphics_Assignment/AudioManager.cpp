#include "AudioManager.h"

//AudioManager* AudioManager::Instance()
//{
//	if (sInstance == nullptr) {
//		sInstance = new AudioManager();
//	}
//
//	return sInstance;
//}
//
//void AudioManager::Release()
//{
//	delete sInstance;
//	sInstance = nullptr;
//}

AudioManager::AudioManager()
{
	SoundEngine->play2D("Assets/breakout.mp3", true);
}

AudioManager::~AudioManager()
{

}
