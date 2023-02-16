#include "Buttons.h"

Buttons::Buttons() {
	m_pReturnToMenuButton = new Texture("Assets/Textures/ReturnMenuButton.png", -.5, -0.01, 0.5, -0.5, GL_RGBA);
	m_pFont = new Font("Assets/Fonts/CarneyText.ttf");
}

Buttons::~Buttons() {
	delete m_pFont;
	m_pFont = nullptr;

	delete m_pReturnToMenuButton;
	m_pReturnToMenuButton = nullptr;
}

void Buttons::Update() {

}

void Buttons::Render() {
	
	m_pReturnToMenuButton->Draw();

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
			m_pFont->RenderText("Click here to return", 285 + i, 315 + j, 1.2, glm::vec3(1.0f, 1.0f, 1.0f));
			m_pFont->RenderText("To the main menu", 310 + i, 245 + j, 1.2, glm::vec3(1.0f, 1.0f, 1.0f)); // These handle the border which is offset slightly from 
		}
	}

	// font color						x	 y	 size
	m_pFont->RenderText("Click here to return", 285, 315, 1.2, glm::vec3(0.0f, 0.0f, 1.0f)); // (1.0f,0.7f,0.0f - b.orange), (1.0f, 0.0f, 0.0f - red), (0.0f, 0.7f, 1.0f -
	m_pFont->RenderText("To the main menu", 310, 245, 1.2, glm::vec3(0.0f, 0.0f, 1.0f)); // (0.0f, 0.0f, 1.0f - blue), (1.0f, 1.0f, 1.0f - white), (0.0f, 0.0f, 0.0f 

	
}

void Buttons::Draw() {
}
