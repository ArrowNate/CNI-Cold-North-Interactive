#include "StartScreen.h"

StartScreen::StartScreen() 
{
	//m_pTimer = Timer::Instance();
	m_pInputManager = InputManager::Instance();
	m_pAudioManager = AudioManager::Instance(); // Should ask Richard if we could do a function for these like InitInstances() or something;
	m_pGraphics = Graphics::Instance();

	PlaySong = true;
	ScreenChoice = 1;
	ScreenSelected = 2;

	m_pFont = new Font("Assets/Fonts/Quentincaps.ttf");

	m_pBackground = new Texture("Assets/Textures/PlateObliteratorMainMenu.png", 1.0, 1.0, -1.0, -1.0, GL_RGBA);
	m_pLogo = new Texture("Assets/Textures/CNiLogo.png", 1.0, -0.72, 0.72, -1.0, GL_RGBA);
	m_pArrow = new Texture("Assets/Textures/MainMenuSelectorArrow.png", -0.47, -0.3, -0.86, -0.45, GL_RGBA);
	m_pArrow2 = new Texture("Assets/Textures/MainMenuSelectorArrow2.png", -0.47, 0.04, -0.86, -0.11, GL_RGBA);

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

	delete m_pArrow;
	m_pArrow = nullptr;

	delete m_pArrow2;
	m_pArrow2 = nullptr;

	delete m_pFont;
	m_pFont = nullptr;
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

	if (glfwGetMouseButton(Graphics::Instance()->GetWindow(), GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
		//std::cout << "click" << std::endl;
		m_pAudioManager->PauseMusic();
		if (m_pInputManager->getmousePosx() >= -0.42 && m_pInputManager->getmousePosx() <= 0.42 && m_pInputManager->getmousePosy() >= -0.13 && m_pInputManager->getmousePosy() <= 0.04) {
			//std::cout << "Nice" << std::endl;
			ScreenSelected = 1;
		}
		else if (m_pInputManager->getmousePosx() >= -0.42 && m_pInputManager->getmousePosx() <= 0.42 && m_pInputManager->getmousePosy() >= -0.47 && m_pInputManager->getmousePosy() <= -0.3)
		{
			ScreenSelected = 0;
		}
	}

	
}

void StartScreen::Render() 
{
	
	m_pBackground->Draw();
	m_pLogo->Draw();

	if (ScreenChoice == 0) {
		m_pArrow->Draw();
	}
	if (ScreenChoice == 1) {
		m_pArrow2->Draw();
	}

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
			m_pFont->RenderText("START GAME", 328 + i, 360 + j, 1.1, glm::vec3(0.0f, 0.0f, 0.0f));
			m_pFont->RenderText("CREDITS", 380 + i, 222 + j, 1.17, glm::vec3(0.0f, 0.0f, 0.0f)); // These handle the border which is offset slightly from 

		}
	}

	// font color
	m_pFont->RenderText("START GAME", 328, 360, 1.1, glm::vec3(1.0f, 0.0f, 0.0f));
	m_pFont->RenderText("CREDITS", 380, 222, 1.17, glm::vec3(1.0f, 0.0f, 0.0f));
}