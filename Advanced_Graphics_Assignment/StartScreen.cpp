#include "StartScreen.h"

StartScreen::StartScreen() 
{
	//m_pTimer = Timer::Instance();
	//m_pInputManager = InputManager::Instance();

	m_pBackground = new Texture("Assets/Textures/CarnvialBackgroundSet.jpg", .3, .3, .3, -.3, -.3, -.3, -.3, .3, GL_RGB);
	//m_pBackground->Parent(this);
	//m_pBackground->Position(Vector3(1000, 800));
}

StartScreen::~StartScreen() 
{
	delete m_pBackground;
	m_pBackground = nullptr;
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
}