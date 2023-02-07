#include "ScreenManager.h"

//Currently working on making the screenmanager function and load up playscreen class

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
	mCurrentScreen = Start;
	m_pStartScreen = new StartScreen();
	m_pPlayScreen = new PlayScreen();

	ScreenChoice = 0;
}

void ScreenManager::Update()
{
	switch (mCurrentScreen)
	{
	case Start:
		m_pStartScreen->Update();
		if (glfwGetKey(Graphics::Instance()->GetWindow(), GLFW_KEY_ENTER) == GLFW_PRESS) {
			mCurrentScreen = Play;
		}
		break;

	case Play:
		if (glfwGetKey(Graphics::Instance()->GetWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS) {
			mCurrentScreen = Start;
		}
		break;
	}
}

void ScreenManager::Render()
{
	switch (mCurrentScreen) {
	case Start:
		m_pStartScreen->Render();
		break;

	case Play:
		m_pPlayScreen->Render();
		break;
	}
}

ScreenManager::~ScreenManager()
{
	delete m_pStartScreen;
	m_pStartScreen = nullptr;

	delete m_pPlayScreen;
	m_pPlayScreen = nullptr;
}
