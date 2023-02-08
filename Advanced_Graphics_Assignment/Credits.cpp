#include "Credits.h"

Credits::Credits()
{
	m_pInputManager = InputManager::Instance();
	m_pAudioManager = AudioManager::Instance();
	m_pGraphics = Graphics::Instance();

	PlaySong = true;
	ScreenSelected = 0;

	m_pBackground = new Texture("Assets/Textures/CarnvialBackgroundSet.png", 1.0, 1.0, -1.0, -1.0, GL_RGBA);
	m_pGeorge = new Texture("Assets/Textures/George.png", 0.0, 0.675, -0.76, 0.525, GL_RGBA);
	m_pDaniel = new Texture("Assets/Textures/Daniel.png", 0.0, 0.31, -0.76, 0.16, GL_RGBA);
	m_pBrandon = new Texture("Assets/Textures/Brandon.png", 0.8, 0.31, 0.16, 0.16, GL_RGBA);
	m_pSam = new Texture("Assets/Textures/Sam.png", 0.0, 0.06, -0.76, -0.09, GL_RGBA);
	m_pMikaelo = new Texture("Assets/Textures/Mikaelo.png", 0.8, 0.06, 0.16, -0.09, GL_RGBA);
	m_pMaksim = new Texture("Assets/Textures/Maksim.png", 0.0, -0.31, -0.76, -0.46, GL_RGBA);
	m_pPatrick = new Texture("Assets/Textures/Patrick.png", 0.8, -0.31, 0.16, -0.46, GL_RGBA);
	m_pLogo = new Texture("Assets/Textures/CNiLogo.png", 1.0, -0.72, 0.72, -1.0, GL_RGBA);
}

Credits::~Credits()
{
	delete m_pBackground;
	m_pBackground = nullptr;

	delete m_pGeorge;
	m_pGeorge = nullptr;

	delete m_pDaniel;
	m_pDaniel = nullptr;

	delete m_pBrandon;
	m_pBrandon = nullptr;

	delete m_pSam;
	m_pSam = nullptr;

	delete m_pMikaelo;
	m_pMikaelo = nullptr;

	delete m_pMaksim;
	m_pMaksim = nullptr;

	delete m_pPatrick;
	m_pPatrick = nullptr;

	delete m_pLogo;
	m_pLogo = nullptr;
}

int Credits::SelectedScreen()
{
	return ScreenSelected;
}

void Credits::setSelectedScreen(int Screen)
{
	ScreenSelected = Screen;
}

void Credits::Update()
{
	if (glfwGetKey(Graphics::Instance()->GetWindow(), GLFW_KEY_BACKSPACE) == GLFW_PRESS) {
		ScreenSelected = 2;
	}
}

void Credits::Render()
{
	m_pBackground->Draw();
	m_pGeorge->Draw();
	m_pDaniel->Draw();
	m_pBrandon->Draw();
	m_pSam->Draw();
	m_pMikaelo->Draw();
	m_pMaksim->Draw();
	m_pPatrick->Draw();
	m_pLogo->Draw();
}