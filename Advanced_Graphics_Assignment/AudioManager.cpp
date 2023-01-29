#include "AudioManager.h"

void processInput(GLFWwindow* window);

AudioManager* AudioManager::sInstance = nullptr;

//SoundEngine = createIrrKlangDevice();

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
	SoundEngine = createIrrKlangDevice();
}

AudioManager::~AudioManager()
{
	delete SoundEngine;
	SoundEngine = nullptr;
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS) {
		SoundEngine->play2D("breakout.mp3", true);
	}
}