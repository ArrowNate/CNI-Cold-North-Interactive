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
	delete m_pStartScreen;
	m_pStartScreen = nullptr;

	delete m_pPlayScreen;
	m_pPlayScreen = nullptr;
}

void ScreenManager::Update()
{

	switch (mCurrentScreen) 
	{
	case Start:
		/*m_pStartScreen->Update();*/
		break;

	case Play:
		m_pPlayScreen->Update();

		/*if (m_pInput->KeyPressed(SDL_SCANCODE_ESCAPE)) {
			mCurrentScreen = Start;
		}*/
		break;
	
	case Logo:

		break;
	}
}

void ScreenManager::Render()
{
	switch (mCurrentScreen) {
	case Start:
		/*m_pStartScreen->Render();*/
		break;

	case Play:
		m_pPlayScreen->Render();
		break;

	case Logo:

		break;
	}
}

ScreenManager::~ScreenManager()
{





}
