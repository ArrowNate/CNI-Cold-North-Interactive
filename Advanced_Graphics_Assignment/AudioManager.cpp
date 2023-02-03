#include "AudioManager.h"

AudioManager* AudioManager::sInstance = nullptr;

AudioManager* AudioManager::Instance() // A singleton assures that one of these objects exists in memory at any given time
{
	if (sInstance == nullptr) {
		sInstance = new AudioManager();
	}

	return sInstance;
}

void AudioManager::Release()
{
	delete sInstance;
	sInstance = nullptr;
}

bool AudioManager::Initialized()
{
	return false;
}

AudioManager::AudioManager()
{
	m_pSoundEngine = createIrrKlangDevice();
}

AudioManager::~AudioManager()
{
	delete m_pSoundEngine;
	m_pSoundEngine = nullptr;
}

void AudioManager::PlayMusic()
{
	
	m_pSoundEngine->play2D("Assets/Music/Survivor_-_Eye_Of_The_Tiger_(Jesusful.com).mp3", true);
}

void AudioManager::PauseMusic()
{

}

void AudioManager::PlaySFX()
{
	//if (sInitialized == false)
	//	return;
}

//void AudioManager::processInput(GLFWwindow* window)
//{
//	//m_pSoundEngine->play2D("Assets/breakout.mp3", true);
//}