#include "StartScreen.h"

StartScreen::StartScreen() 
{
	//m_pTimer = Timer::Instance();
	//m_pInputManager = InputManager::Instance();

	m_pBackground = new Texture("Assets/Textures/CarnvialBackgroundSet.png", 1, 1, 1, -1, -1, -1, -1, 1, GL_RGBA); // First Two Numbers are for TOP RIGHT, 3RD and 4TH numbers are for BOTTOM RIGHT, 5TH and 6TH Numbers are for BOTTOM LEFT, 7TH and 8TH numbers are for TOP LEFT //
	m_pPlate = new Texture("Assets/Textures/Plate.png", .85, .85, .85, .47, .47, .47, .47, .85, GL_RGBA);
	//m_pPlate->Position(Vector3(300, 100));
	m_pLogo = new Texture("Assets/Textures/CNiLogo.png", .19, .19, .19, -.19, -.19, -.19, -.19, .19, GL_RGBA);
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
	//m_pBackground->Update();
}

void StartScreen::Render() 
{
	m_pBackground->Draw();
	m_pPlate->Draw();
	m_pLogo->Draw();
}