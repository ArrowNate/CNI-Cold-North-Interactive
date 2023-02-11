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
	m_pCredits = new Credits();
	m_pPlayScreen = new PlayScreen();

	Screens.push_back(m_pStartScreen);
	Screens.push_back(m_pPlayScreen);
	Screens.push_back(m_pCredits);

	ScreenChoice = 2;
}

void ScreenManager::Update()
{
	switch (ScreenChoice)
	{
	case Start:
		m_pStartScreen->Update();
		m_pCredits->setSelectedScreen(0);
		m_pPlayScreen->setSelectedScreen(1);
		ScreenChoice = m_pStartScreen->SelectedScreen();
		break;

	case Credit:
		m_pCredits->Update();
		m_pStartScreen->setSelectedScreen(2);
		ScreenChoice = m_pCredits->SelectedScreen();
		break;

	case Play:
		m_pPlayScreen->Update();
		m_pStartScreen->setSelectedScreen(2);
		ScreenChoice = m_pPlayScreen->SelectedScreen();
<<<<<<< HEAD
=======
		break;
<<<<<<< HEAD

	case Splash:
		m_pSplashScreen->Update();
		//m_pSplashScreen->setSelectedScreen(2);
		ScreenChoice = m_pSplashScreen->SelectedScreen();
>>>>>>> parent of 342c4a5 (Merge branch 'main' into Patrick)
		break;
=======
>>>>>>> parent of eb359a6 (1.0.0.6)
	}
}

void ScreenManager::Render()
{
	switch (ScreenChoice) {
	case Start:
		m_pStartScreen->Render();
		break;

	case Credit:
		m_pCredits->Render();
		break;

	case Play:
		m_pPlayScreen->Render();
<<<<<<< HEAD
=======
		break;
<<<<<<< HEAD

	case Splash:
		m_pSplashScreen->Render();
>>>>>>> parent of 342c4a5 (Merge branch 'main' into Patrick)
		break;
=======
>>>>>>> parent of eb359a6 (1.0.0.6)
	}
}

ScreenManager::~ScreenManager()
{
	delete m_pStartScreen;
	m_pStartScreen = nullptr;

	delete m_pCredits;
	m_pCredits = nullptr;

	delete m_pPlayScreen;
	m_pPlayScreen = nullptr;
}