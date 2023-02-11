#include "Credits.h"

Credits::Credits()
{
	m_pInputManager = InputManager::Instance();
	m_pAudioManager = AudioManager::Instance();
	m_pGraphics = Graphics::Instance();

	PlaySong = true;
	ScreenSelected = 0;

	m_pFont = new Font("Assets/Fonts/Quentincaps.ttf");
	m_pFont2 = new Font("Assets/Fonts/CarneyText.ttf");

	m_pBackground = new Texture("Assets/Textures/CarnvialBackgroundSet.png", 1.0, 1.0, -1.0, -1.0, GL_RGBA);
	m_pLogo = new Texture("Assets/Textures/CNiLogo.png", 1.0, -0.72, 0.72, -1.0, GL_RGBA);
}

Credits::~Credits()
{
	delete m_pBackground;
	m_pBackground = nullptr;

	delete m_pLogo;
	m_pLogo = nullptr;

	delete m_pFont;
	m_pFont = nullptr;

	delete m_pFont2;
	m_pFont2 = nullptr;
}

int Credits::SelectedScreen()
{
	return ScreenSelected;
}

void Credits::setSelectedScreen(int Screen)
{
	ScreenSelected = Screen;
}

void Credits::Update()
{
	if (glfwGetKey(Graphics::Instance()->GetWindow(), GLFW_KEY_BACKSPACE) == GLFW_PRESS) {
		ScreenSelected = 2;
	}
}

void Credits::Render()
{
	m_pBackground->Draw();;
	m_pLogo->Draw();

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
			m_pFont->RenderText("RICHARD ALS", 68 + i, 622 + j, 1.2, glm::vec3(0.0f, 0.0f, 0.0f));
			m_pFont->RenderText("DANIEL DEPAULO", 550 + i, 622 + j, 1.2, glm::vec3(0.0f, 0.0f, 0.0f)); // These handle the border which is offset slightly from 
			m_pFont->RenderText("GEORGE EDMON", 68 + i, 480 + j, 1.09, glm::vec3(0.0f, 0.0f, 0.0f));  // regular text. Gives the illusion of the border.
			m_pFont->RenderText("PATRICK FOSTER", 525 + i, 480 + j, 1.1, glm::vec3(0.0f, 0.0f, 0.0f));
			m_pFont->RenderText("MAKSIM KNOKHINOV", 68 + i, 375 + j, 1.1, glm::vec3(0.0f, 0.0f, 0.0f));
			m_pFont->RenderText("SAM SAMAROO", 480 + i, 375 + j, 1.0, glm::vec3(0.0f, 0.0f, 0.0f));
			m_pFont->RenderText("MIKAELO SAN JOSE", 68 + i, 224 + j, 0.9, glm::vec3(0.0f, 0.0f, 0.0f));
			m_pFont->RenderText("BRANDON SHAW", 525 + i, 224 + j, 0.98, glm::vec3(0.0f, 0.0f, 0.0f));
			m_pFont2->RenderText("COLD NORTH ", 130 + i, 41 + j, 1.5, glm::vec3(1.0f, 1.0f, 1.0f));
			m_pFont2->RenderText("INTERACTIVE: ", 500 + i, 50 + j, 0.9, glm::vec3(0.0f, 0.0f, 1.0f));
		}
	}

	// font color						x	 y	 size
	m_pFont->RenderText("RICHARD ALS", 68, 622, 1.2, glm::vec3(1.0f, 0.0f, 0.0f)); // (1.0f,0.7f,0.0f - b.orange), (1.0f, 0.0f, 0.0f - red), (0.0f, 0.7f, 1.0f - 
	m_pFont->RenderText("DANIEL DEPAULO", 550, 622, 1.2, glm::vec3(1.0f, 0.0f, 0.0f)); // (0.0f, 0.0f, 1.0f - blue), (1.0f, 1.0f, 1.0f - white), (0.0f, 0.0f, 0.0f 
	m_pFont->RenderText("GEORGE EDMON", 68, 480, 1.09, glm::vec3(1.0f, 0.0f, 0.0f));                                                                 // black)
	m_pFont->RenderText("PATRICK FOSTER", 525, 480, 1.1, glm::vec3(1.0f, 0.0f, 0.0f));
	m_pFont->RenderText("MAKSIM KNOKHINOV", 68, 375, 1.1, glm::vec3(1.0f, 0.0f, 0.0f));
	m_pFont->RenderText("SAM SAMAROO", 480, 375, 1.0, glm::vec3(1.0f, 0.0f, 0.0f));
	m_pFont->RenderText("MIKAELO SAN JOSE", 68, 224, 0.9, glm::vec3(1.0f, 0.0f, 0.0f));
	m_pFont->RenderText("BRANDON SHAW", 525, 224, 0.98, glm::vec3(1.0f, 0.0f, 0.0f));
	m_pFont2->RenderText("COLD NORTH ", 130, 41, 1.5, glm::vec3(0.0f, 0.0f, 1.0f));
	m_pFont2->RenderText("INTERACTIVE: ", 500, 50, 0.9, glm::vec3(1.0f, 1.0f, 1.0f));
}