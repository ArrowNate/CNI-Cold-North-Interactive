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
	m_pLevelManager = new LevelManager();
	m_pCredits = new Credits();
	//m_pPlayScreen = new PlayScreen();
	m_pSplashScreen = new SplashScreen();
	m_pGameOverScreen = new GameOverScreen();
	

	//Screens.push_back(m_pStartScreen);
	//Screens.push_back(m_pPlayScreen);
	//Screens.push_back(m_pCredits);


	ScreenChoice = Start;

	mLevelReset = true;
}

void ScreenManager::Update()
{
	switch (ScreenChoice)
	{
	case Start:
		m_pStartScreen->Update();
		m_pCredits->setSelectedScreen(0);
		m_pLevelManager->setSelectedScreen(1);
		ScreenChoice = m_pStartScreen->SelectedScreen();
		
		
		if (mLevelReset = true) {
			
			m_pLevelManager->Reset();
			
		}

		mLevelReset = false;
		
		break;

	case Credit:
		m_pCredits->Update();
		m_pStartScreen->setSelectedScreen(2);
		ScreenChoice = m_pCredits->SelectedScreen();
		break;

	case Play:
		m_pLevelManager->Update();
		m_pStartScreen->setSelectedScreen(2);
		m_pGameOverScreen->setSelectedScreen(4);
		ScreenChoice = m_pLevelManager->SelectedScreen();
		
		mLevelReset = false;

		break;

	case Splash:
		m_pSplashScreen->Update();
		//m_pSplashScreen->setSelectedScreen(2);
		ScreenChoice = m_pSplashScreen->SelectedScreen();
		break;

	case GameOver:
		m_pGameOverScreen->Update();
		//m_pStartScreen->setSelectedScreen(2);
		ScreenChoice = m_pGameOverScreen->SelectedScreen();
		
		if (mLevelReset = false) {
			m_pLevelManager->Reset();
			mLevelReset = false;
		}
		break;
	}
}

void ScreenManager::LateUpdate() {

	if (ScreenChoice == Play) {
		m_pLevelManager->LateUpdate();
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
		m_pLevelManager->Render();
		break;

	case Splash:
		m_pSplashScreen->Render();
		break;

	case GameOver:
		m_pGameOverScreen->Render();
		break;
	}
}

ScreenManager::~ScreenManager()
{
	delete m_pStartScreen;
	m_pStartScreen = nullptr;

	delete m_pCredits;
	m_pCredits = nullptr;

	delete m_pLevelManager;
	m_pLevelManager = nullptr;

	delete m_pGameOverScreen;
	m_pGameOverScreen = nullptr;
}