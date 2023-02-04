#include "StartScreen.h"

StartScreen::StartScreen() 
{
	//m_pTimer = Timer::Instance();
	m_pInputManager = InputManager::Instance();

	m_pBackground = new Texture("Assets/Textures/CarnvialBackgroundSet.png", 1.0, -1, GL_RGBA);
	m_pPlate = new Texture("Assets/Textures/Plate.png", 0.47, 0.8,  GL_RGBA);

	m_pLogo = new Texture("Assets/Textures/CNiLogo.png", -0.71, -1.0, GL_RGBA);
	//m_pBackground->Parent(this);
	//m_pBackground->Position(Vector3(1000, 800));
}

StartScreen::~StartScreen() 
{
	delete m_pBackground;
	m_pBackground = nullptr;

	delete m_pPlate;
	m_pPlate = nullptr;

	delete m_pLogo;
	m_pLogo = nullptr;
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
	m_pInputManager->Update();

	if (glfwGetKey(Graphics::Instance()->GetWindow(), GLFW_KEY_DOWN) == GLFW_PRESS) {
		ChangeSelectedMode(1);
	}
	else if (glfwGetKey(Graphics::Instance()->GetWindow(), GLFW_KEY_UP) == GLFW_PRESS) {
		ChangeSelectedMode(-1);
	}
}

void StartScreen::Render() 
{
	m_pBackground->Draw();
	m_pPlate->Draw();
	m_pLogo->Draw();
}