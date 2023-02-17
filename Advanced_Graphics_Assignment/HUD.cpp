#include "HUD.h"
#include "GameOverScreen.h"


HUD::HUD() {

	m_pFont = new Font("Assets/Fonts/CarneyText.ttf");
	m_pHUDBorder = new Texture("Assets/Textures/HUDBorder1.png", 1.0, 1.0, -1.0, -1.0, GL_RGBA); 
	m_pGameOverScreen = new GameOverScreen();
	
	timeLeft = 30;
	Point = 0;
	Shots = 15;
}

HUD::~HUD() {
	delete m_pFont;
	m_pFont = nullptr;

	delete m_pHUDBorder;
	m_pHUDBorder = nullptr;
}

void HUD::DecreaseTimer() {
	double currentTime = glfwGetTime();
	if (currentTime - previousTime >= 1) {
		timeLeft--;
		previousTime = currentTime;

		if (timeLeft <= 0) {
			timeLeft = 0;
		}
	}
	if (timeLeft != 0) {
		
	}
	/*if (timeLeft == 0) {
		m_pGameOverScreen->Render();
	}*/
}

void HUD::Update() {
	DecreaseTimer();

	/*if (timeLeft == 0) {
		m_pGameOverScreen->Update();
	}*/
}

void HUD::Score()
{
	Point += 100;
}


void HUD::DecreaseAmmo()
{
	Shots -= 1;
}


void HUD::Draw() {
	
	//if (timeLeft != 0) {
	m_pHUDBorder->Draw();

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
				m_pFont->RenderText("SCORE: " + std::to_string(Point), 35 + i, 733 + j, 1.4, glm::vec3(1.0f, 1.0f, 1.0f));
				m_pFont->RenderText("SHOTS LEFT: " + std::to_string(Shots), 650 + i, 738 + j, 1.2, glm::vec3(1.0f, 1.0f, 1.0f)); // These handle the border which is offset slightly from
				m_pFont->RenderText("TIME: " + std::to_string(timeLeft), 7 + i, 10 + j, 1.2, glm::vec3(1.0f, 1.0f, 1.0f));     // regular text. Gives the illusion of the border.

			}
		}

		// font color
		m_pFont->RenderText("SCORE: " + std::to_string(Point), 35, 733, 1.4, glm::vec3(0.0f, 0.0f, 0.0f)); // (1.0f,0.7f,0.0f - b.orange), (1.0f, 0.0f, 0.0f - red), (0.0f, 0.7f, 1.0f 
		m_pFont->RenderText("SHOTS LEFT: " + std::to_string(Shots), 650, 738, 1.2, glm::vec3(0.0f, 0.0f, 0.0f)); // (0.0f, 0.0f, 1.0f - blue), (1.0f, 1.0f, 1.0f - white), (0.0f, 0.0f, 0.0f
		m_pFont->RenderText("TIME: " + std::to_string(timeLeft), 7, 10, 1.2, glm::vec3(0.0f, 0.0f, 0.0f));
		// black)
	//}

	/*if (timeLeft == 0) {
		m_pGameOverScreen->Render();
	}*/
}





int HUD::GetShots() {
	return Shots;
}

int HUD::GetTime() {
	return timeLeft;
}

void HUD::Reset() {
	Point = 0;
	Shots = 15;
	timeLeft = 30;
}

