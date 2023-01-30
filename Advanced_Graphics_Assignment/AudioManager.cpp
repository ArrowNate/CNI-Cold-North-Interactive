#include "AudioManager.h"

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
	ISoundEngine* SoundEngine = createIrrKlangDevice();
}

AudioManager::~AudioManager()
{
	delete SoundEngine;
	SoundEngine = nullptr;
}

void AudioManager::PlayMusic()
{
}

void AudioManager::processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS) {
		SoundEngine->play2D("breakout.mp3", true);
	}
}