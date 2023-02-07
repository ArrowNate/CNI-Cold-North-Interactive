#include "StartScreen.h"

StartScreen::StartScreen() 
{
	//m_pTimer = Timer::Instance();
	m_pInputManager = InputManager::Instance();
	m_pAudioManager = AudioManager::Instance();
	m_pGraphics = Graphics::Instance();

	PlaySong = true;

	m_pBackground = new Texture("Assets/Textures/PlateObliteratorMainMenu.png", 1.0, 1.0, -1.0, -1.0, GL_RGBA);
	m_pLogo = new Texture("Assets/Textures/CNiLogo.png", 1.0, -0.72, 0.72, -1.0, GL_RGBA);
	m_pStartGame = new Texture("Assets/Textures/StartGameQ.png", 0.37, 0.04, -0.39, -0.11, GL_RGBA);
	m_pCredits = new Texture("Assets/Textures/CreditsQ.png", 0.37, -0.3, -0.39, -0.45, GL_RGBA);
	m_pArrow = new Texture("Assets/Textures/MainMenuSelectorArrow.png", 0.50, 0.04, -0.39, -0.11, GL_RGBA);
	//m_pBackground->Parent(this);
	//m_pBackground->Position(Vector3(1000, 800));
}

StartScreen::~StartScreen() 
{
	delete m_pBackground;
	m_pBackground = nullptr;

	delete m_pLogo;
	m_pLogo = nullptr;

	delete m_pStartGame;
	m_pStartGame = nullptr;

	delete m_pCredits;
	m_pCredits = nullptr;

	delete m_pArrow;
	m_pArrow = nullptr;
}

void StartScreen::ChangeSelectedMode(int change)
{
	mSelectedMode += change;

	if (mSelectedMode < 0) {
		mSelectedMode = 1;
	}
	else if (mSelectedMode > 1) {
		mSelectedMode = 0;
	}

	//m_pCursor->Position(mCursorStartPos + mCursorOffset * (float)mSelectedMode);
}

int StartScreen::SelectedMode()
{
	return mSelectedMode;
}

void StartScreen::Update() 
{
	if (PlaySong == true) {
		m_pAudioManager->PlayMusic();
		PlaySong = false;
	}

	m_pInputManager->processInput(Graphics::Instance()->GetWindow());

	if (glfwGetKey(Graphics::Instance()->GetWindow(), GLFW_KEY_S) == GLFW_PRESS) {
		ChangeSelectedMode(1);
	}
	else if (glfwGetKey(Graphics::Instance()->GetWindow(), GLFW_KEY_W) == GLFW_PRESS) {
		ChangeSelectedMode(-1);
	}
}

void StartScreen::Render() 
{
	m_pBackground->Draw();
	m_pLogo->Draw();
	m_pStartGame->Draw();
	m_pCredits->Draw();

	if (mSelectedMode == 0) {
		m_pArrow->Draw();
	}
	else if (mSelectedMode == 1) {

	}
}