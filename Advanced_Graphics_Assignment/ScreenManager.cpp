#include "ScreenManager.h"

ScreenManager* ScreenManager::sInstance = nullptr;

ScreenManager* ScreenManager::Instance() 
{
	if (sInstance == nullptr) {
		sInstance = new ScreenManager();
	}

	return sInstance;
}

void ScreenManager::Release() 
{
	delete sInstance;
	sInstance = nullptr;
}

ScreenManager::ScreenManager() 
{
	m_pStartScreen = new StartScreen();
	m_pPlayScreen = new PlayScreen();
}

void ScreenManager::Update()
{

	switch (mCurrentScreen) 
	{
	case Start:
		break;

	case Play:
		break;

	}
}

void ScreenManager::Render()
{
	switch (mCurrentScreen) {
	case Start:
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {

		}
		break;

	case Play:
		if (glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS) {

		}
		break;
	}
}

ScreenManager::~ScreenManager()
{
	delete m_pPlayScreen;
	m_pPlayScreen = nullptr;

	delete m_pStartScreen;
	m_pStartScreen = nullptr;
}
