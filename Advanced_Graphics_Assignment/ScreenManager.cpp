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
	mCurrentScreen = Logo;
}

void ScreenManager::Update()
{

	switch (mCurrentScreen) 
	{
	case Start:

		break;

	case Play:

		break;
	
	case Logo:

		break;
	}
}

void ScreenManager::Render()
{
	switch (mCurrentScreen) {
	case Start:

		break;

	case Play:


		break;

	case Logo:



		break;
	}
}

ScreenManager::~ScreenManager()
{





}
