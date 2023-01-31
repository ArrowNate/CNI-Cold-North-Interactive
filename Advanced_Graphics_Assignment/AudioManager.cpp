#include "AudioManager.h"

using namespace irrklang;

AudioManager* AudioManager::sInstance = nullptr;

AudioManager* AudioManager::Instance()
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
	ISoundEngine* m_pSoundEngine = createIrrKlangDevice();
}

AudioManager::~AudioManager()
{
	delete m_pSoundEngine;
	m_pSoundEngine = nullptr;
}

void AudioManager::PlayMusic()
{

}

void AudioManager::PauseMusic()
{

}

void AudioManager::PlaySFX()
{

}

void AudioManager::processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS) {
		m_pSoundEngine->play2D("Assets/breakout.mp3", true);
	}
}