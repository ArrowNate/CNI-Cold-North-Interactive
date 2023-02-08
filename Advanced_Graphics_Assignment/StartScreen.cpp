#include "StartScreen.h"
#include "Font.h"
#include "Shader.h"
#include FT_FREETYPE_H
#include "stb_image.h"
#include <GLFW/glfw3.h>
#include <ft2build.h>
#include <glm/vec3.hpp>

StartScreen::StartScreen()
{

	//m_pTimer = Timer::Instance();
	m_pInputManager = InputManager::Instance();
	m_pAudioManager = AudioManager::Instance();
	m_pGraphics = Graphics::Instance();

	PlaySong = true;

	m_pBackground = new Texture("Assets/Textures/MainMenuBackground.png", 1.0, 1.0, -1, -1, GL_RGBA);

	//m_pPlate = new Texture("Assets/Textures/Plate.png", 0.2, -.2,  GL_RGBA);
	/*m_pStartButtonText = new Texture("START GAME", "Assets/Fonts/CarneyText1.ttf", 32, Vector3(1, 1, 1), 0.5f, 0.8f);*/ // I do not believe this should be texture,                                                                                                                     possibly Font*? 

	m_pLogo = new Texture("Assets/Textures/CNiLogo.png", 1, -0.8, 0.8,-1,  GL_RGBA);
	m_pLogo->Parent(this);
	m_pLogo->Position(Vector3(.5, .5,0));
}

StartScreen::~StartScreen()
{
	delete m_pBackground;
	m_pBackground = nullptr;

	/*delete m_pPlate;
	m_pPlate = nullptr;*/

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
	if (PlaySong == true) {
		m_pAudioManager->PlayMusic();
		PlaySong = false;
	}

	m_pInputManager->processInput(Graphics::Instance()->GetWindow());

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
	//m_pPlate->Draw();
	m_pLogo->Draw();
}
