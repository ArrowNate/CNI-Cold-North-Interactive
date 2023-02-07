#include "SplashScreen.h"

SplashScreen::SplashScreen()
{
	m_pTimer = Timer::Instance();
	m_pInputManager = InputManager::Instance();
	m_pAudioManager = AudioManager::Instance();
	m_pGraphics = Graphics::Instance();

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
}

void SplashScreen::Render()
{
	m_pLogo->Draw();
}