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
		m_pPlayScreen->Render();
		break;

	case Play:

		break;
	}
}

ScreenManager::~ScreenManager()
{
	delete m_pPlayScreen;
	m_pPlayScreen = nullptr;

}
