#include "StartScreen.h"

StartScreen::StartScreen() 
{
	//m_pTimer = Timer::Instance();
	m_pInputManager = InputManager::Instance();
	m_pAudioManager = AudioManager::Instance();
	m_pGraphics = Graphics::Instance();

	PlaySong = true;
	ScreenChoice = 1;
	ScreenSelected = 2;

	m_pBackground = new Texture("Assets/Textures/PlateObliteratorMainMenu.png", 1.0, 1.0, -1.0, -1.0, GL_RGBA);
	m_pLogo = new Texture("Assets/Textures/CNiLogo.png", 1.0, -0.72, 0.72, -1.0, GL_RGBA);
	m_pStartGame = new Texture("Assets/Textures/StartGameQ.png", 0.37, 0.04, -0.39, -0.11, GL_RGBA);
	m_pCredits = new Texture("Assets/Textures/CreditsQ.png", 0.37, -0.3, -0.39, -0.45, GL_RGBA);
	m_pArrow = new Texture("Assets/Textures/MainMenuSelectorArrow.png", -0.47, -0.3, -0.86, -0.45, GL_RGBA);
	m_pArrow2 = new Texture("Assets/Textures/MainMenuSelectorArrow2.png", -0.47, 0.04, -0.86, -0.11, GL_RGBA);
	//m_pBackground->Parent(this);
	//m_pBackground->Position(Vector3(1000, 800));
}

StartScreen::~StartScreen() 
{
	AudioManager::Release();
	m_pAudioManager = nullptr;

	InputManager::Release();
	m_pInputManager = nullptr;

	Graphics::Release();
	m_pGraphics = nullptr;

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

	delete m_pArrow2;
	m_pArrow2 = nullptr;
}

void StartScreen::ChangeSelectedMode(int change)
{
	ScreenChoice += change;

	if (ScreenChoice < 0) {
		ScreenChoice = 1;
	}
	else if (ScreenChoice > 1) {
		ScreenChoice = 0;
	}

	//m_pCursor->Position(mCursorStartPos + mCursorOffset * (float)mSelectedMode);
}

int StartScreen::SelectedMode()
{
	return ScreenChoice;
}

int StartScreen::SelectedScreen()
{
	return ScreenSelected;
}

void StartScreen::setSelectedScreen(int Screen)
{
	ScreenSelected = Screen;
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

	if (glfwGetKey(Graphics::Instance()->GetWindow(), GLFW_KEY_ENTER) == GLFW_PRESS) {
		ScreenSelected = ScreenChoice;
		m_pAudioManager->PauseMusic();
	}

	
}

void StartScreen::Render() 
{
	m_pBackground->Draw();
	m_pLogo->Draw();
	m_pStartGame->Draw();
	m_pCredits->Draw();

	if (ScreenChoice == 0) {
		m_pArrow->Draw();
	}
	if (ScreenChoice == 1) {
		m_pArrow2->Draw();
	}
}