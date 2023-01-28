#include "AudioManager.h"

void processInput(GLFWwindow* window);

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

AudioManager::AudioManager()
{
	SoundEngine = createIrrKlangDevice();
}

AudioManager::~AudioManager()
{

}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		SoundEngine->play2D("breakout.mp3", true);
}