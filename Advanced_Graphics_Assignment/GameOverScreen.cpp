#include "GameOverScreen.h"

GameOverScreen::GameOverScreen() {

	m_pLevelManager = new LevelManager();

	m_pFont = new Font("Assets/Fonts/CarneyText.ttf");
	m_pGameOverBackground = new Texture("Assets/Textures/GameOverBackground.png", 1.0, 1.0, -1.0, -1.0, GL_RGBA);
	m_pButtons = new Buttons();

	ScreenSelected = 4;
	
}

GameOverScreen::~GameOverScreen() {

	LevelManager::Release();
	m_pLevelManager = nullptr;

	delete m_pFont;
	m_pFont = nullptr;

	delete m_pGameOverBackground;
	m_pGameOverBackground = nullptr;

	delete m_pButtons;
	m_pButtons = nullptr;
}

void GameOverScreen::Update() {

	if (glfwGetMouseButton(Graphics::Instance()->GetWindow(), GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
		//std::cout << "click" << std::endl;
		//ScreenSelected = 2;

		if (m_pInputManager->getmousePosx() >= -0.48 && m_pInputManager->getmousePosx() <= -0.011 && m_pInputManager->getmousePosy() >= -0.48 && m_pInputManager->getmousePosy() <= -0.02) {
			//std::cout << "Going to Menu" << std::endl;
			ScreenSelected = 2;
			//m_pAudioManager->PauseMusic();
		}

		if (m_pInputManager->getmousePosx() >= 0.008 && m_pInputManager->getmousePosx() <= 0.48 && m_pInputManager->getmousePosy() >= -0.48 && m_pInputManager->getmousePosy() <= -0.02) {
			//std::cout << "Going to Next Level" << std::endl;
			//int test = 0;
			//test = (test += 1);
			//ScreenSelected = 2;
			//m_pAudioManager->PauseMusic();
			//m_pLevelManager->Reset();
			m_pLevelManager->NextLevel();
			//m_pLevelManager->setCurrentLevel(test);
			ScreenSelected = 1;

			
		}
	}
	
}

void GameOverScreen::ReturnToMainMenu() {

}

void GameOverScreen::Render() {

	m_pGameOverBackground->Draw();
	m_pButtons->Render();
	const int thickness = 2; // This is the thickness of the border around the text

	for (int i = -thickness; i <= thickness; ++i) // inner loop repeats over j from -thickness to thickness same with i as well. 

	{
		for (int j = -thickness; j <= thickness; ++j)
		{
			if (i == 0 && j == 0) // we check if i and j are equal to 0 and if they are, the code goes to the continue statement because when i and j = 0,
			{					  // the center of the border would basically cover the text and we don't want the border over the text it looks horrible.	
				continue;
			}

			// border color
			m_pFont->RenderText("GAME OVER", 180 + i, 550 + j, 3.0, glm::vec3(1.0f, 0.0f, 0.0f));
			m_pFont->RenderText("Thanks For Playing!", 135 + i, 450 + j, 2.1, glm::vec3(1.0f, 0.0f, 0.0f)); // These handle the border which is offset slightly from 
		}
	}

	// font color						x	 y	 size
	m_pFont->RenderText("GAME OVER", 180, 550, 3.0, glm::vec3(0.0f, 0.0f, 0.0f)); // (1.0f,0.7f,0.0f - b.orange), (1.0f, 0.0f, 0.0f - red), (0.0f, 0.7f, 1.0f - 
	m_pFont->RenderText("Thanks For Playing!", 135, 450, 2.1, glm::vec3(0.0f, 0.0f, 0.0f)); // (0.0f, 0.0f, 1.0f - blue), (1.0f, 1.0f, 1.0f - white), (0.0f, 0.0f, 0.0f 
	
}


int GameOverScreen::SelectedMode()
{
	return ScreenChoice;
}

int GameOverScreen::SelectedScreen()
{
	return ScreenSelected;
}

void GameOverScreen::setSelectedScreen(int Screen)
{
	ScreenSelected = Screen;
}

void GameOverScreen::CurrentLevel(int currentlevel) {
	currentlevel = (currentlevel + 1);
	m_pLevelManager->setCurrentLevel(currentlevel);
}

