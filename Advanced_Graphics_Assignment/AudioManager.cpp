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

	m_pSoundEngine->play2D("Assets/Music/urvivor_-_Eye_Of_The_Tiger_(Jesusful.com).mp3", true);
}

void AudioManager::PauseMusic()
{
	m_pSoundEngine->stopAllSounds();
}

void AudioManager::PlaySFX()
{
	//if (sInitialized == false)
	//	return;
}

void AudioManager::PlayMusic2(const char filepath[50], bool loop)
{
	m_pSoundEngine->play2D(filepath, loop);
}

void AudioManager::PlayMusic3D(const char filepath[50], float x, float y, float z, bool loop) {
	m_pSoundEngine->play3D(filepath, vec3df(x, y, z), loop );
}