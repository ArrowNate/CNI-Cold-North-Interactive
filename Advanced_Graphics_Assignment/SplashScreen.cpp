#include "SplashScreen.h"

SplashScreen::SplashScreen()
{
	m_pTimer = Timer::Instance();
	m_pInputManager = InputManager::Instance();
	m_pAudioManager = AudioManager::Instance();
	m_pGraphics = Graphics::Instance();
	mSplashTotalTime = 1.0f;
	mSplashTimer = 6.0f;
	mSplashDone = false;
	PlayIntro = true;

	ScreenSelected = 3;


	m_pLogo = new Texture("Assets/Textures/CNiLogo.png", 1.0, 1.0, -1.0, -1.0, GL_RGBA);
}
SplashScreen::~SplashScreen()
{
	delete m_pLogo;
	m_pLogo = nullptr;
}

int SplashScreen::SelectedMode()
{
	return ScreenChoice;
}

int SplashScreen::SelectedScreen()
{
	return ScreenSelected;
}

void SplashScreen::setSelectedScreen(int Screen)
{
	ScreenSelected = Screen;
}

void SplashScreen::Update()
{
	m_pInputManager->processInput(Graphics::Instance()->GetWindow());
	mSplashTimer += m_pTimer->DeltaTime();
	if (PlayIntro == true) {
		//m_pAudioManager->PlayIntro();
		PlayIntro = false;
	}

	if (!mSplashDone) {
		if (mSplashTimer >= mSplashTotalTime) {
			mSplashDone = true;
			ScreenSelected = 2;
			//m_pAudioManager->PauseIntro();
		}
	}

}


void SplashScreen::Render()
{
	m_pLogo->Draw();
}