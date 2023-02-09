#include "PlayScreen.h"

PlayScreen::PlayScreen()
{
	m_pInputManager = InputManager::Instance();
	m_pAudioManager = AudioManager::Instance();
	m_pGraphics = Graphics::Instance();

	ScreenSelected = 1;

	m_pBackdrop = new Texture("Assets/Textures/CarnivalSetWaves.png", 1.0, 1.0, -1.0, -1.0, GL_RGBA);
}

PlayScreen::~PlayScreen()
{
	delete m_pBackdrop;
	m_pBackdrop = nullptr;
}

int PlayScreen::SelectedScreen()
{
	return ScreenSelected;
}

void PlayScreen::setSelectedScreen(int Screen)
{
	ScreenSelected = Screen;
}

void PlayScreen::Update()
{
	if (glfwGetKey(Graphics::Instance()->GetWindow(), GLFW_KEY_BACKSPACE) == GLFW_PRESS) {
		ScreenSelected = 2;
	}
}

void PlayScreen::Render()
{
	m_pBackdrop->Draw();
}