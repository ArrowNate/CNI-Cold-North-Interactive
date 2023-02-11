#include "SplashScreen.h"

SplashScreen::SplashScreen()
{
	m_pTimer = Timer::Instance();
	m_pInputManager = InputManager::Instance();
	m_pAudioManager = AudioManager::Instance();
	m_pGraphics = Graphics::Instance();
	mSplashTotalTime = 1.0f;
	mSplashTimer = 0.0f;
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
	std::cout << mSplashTimer;
	if (PlayIntro == true) {
		m_pAudioManager->PlayMusic3D("Assets/Music/SplashSound.wav", -2.0f, -3, 1);
		PlayIntro = false;
	}

	if (!mSplashDone) {
		if (mSplashTimer >= mSplashTotalTime) {
			m_pAudioManager->PauseMusic();
			mSplashDone = true;
			ScreenSelected = 2;
		}
	}

}


void SplashScreen::Render()
{
	m_pLogo->Draw();
}