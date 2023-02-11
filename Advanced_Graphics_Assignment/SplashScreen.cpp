#include "SplashScreen.h"

SplashScreen::SplashScreen()
{
	m_pTimer = Timer::Instance();
	m_pInputManager = InputManager::Instance();
	m_pAudioManager = AudioManager::Instance();
	m_pGraphics = Graphics::Instance();
	mSplashTotalTime = 5.0f;
	mSplashTimer = 0.0f;
	mSplashDone = false;

	m_pLogo = new Texture("Assets/Textures/CNiLogo.png", 1.0, 1.0, -1.0, -1.0, GL_RGBA);
}
SplashScreen::~SplashScreen()
{
	delete m_pLogo;
	m_pLogo = nullptr;
}

void SplashScreen::Update()
{
	m_pInputManager->processInput(Graphics::Instance()->GetWindow());
	mSplashTimer += m_pTimer->DeltaTime();

	if (!mSplashDone) {
		if (mSplashTimer >= mSplashTotalTime) {
			mSplashDone = true;
		}
	}
}

void SplashScreen::Render()
{
	m_pLogo->Draw();
}