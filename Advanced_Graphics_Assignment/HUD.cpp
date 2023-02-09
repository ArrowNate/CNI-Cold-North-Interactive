#include "HUD.h"

HUD::HUD() {
	
}

HUD::~HUD() {
	
}

void HUD::Update() {

}

void HUD::Draw() {

	const int thickness = 3; // This is the thickness of the border around the text

	for (int i = -thickness; i <= thickness; ++i) // inner loop repeats over j from -thickness to thickness same with i as well. 

	{
		for (int j = -thickness; j <= thickness; ++j)
		{
			if (i == 0 && j == 0) // we check if i and j are equal to 0 and if they are, the code goes to the continue statement because when i and j = 0,
			{					  // the center of the border would basically cover the text and we don't want the border over the text it looks horrible.	
				continue;
			}

			// border color
			m_pFont->RenderText("SCORE: ", 7 + i, 763 + j, 1.1, glm::vec3(1.0f, 1.0f, 1.0f));
			m_pFont->RenderText("SHOTS LEFT: ", 680 + i, 763 + j, 1.1, glm::vec3(1.0f, 1.0f, 1.0f)); // These handle the border which is offset slightly from 
			m_pFont->RenderText("TIME LEFT: ", 7 + i, 10 + j, 1.1, glm::vec3(1.0f, 1.0f, 1.0f));     // regular text. Gives the illusion of the border.
		}
	}

	// font color
	m_pFont->RenderText("SCORE: ", 7, 763, 1.1, glm::vec3(0.0f, 0.0f, 0.0f)); // (1.0f,0.7f,0.0f - b.orange), (1.0f, 0.0f, 0.0f - red), (0.0f, 0.7f, 1.0f - b.blue)
	m_pFont->RenderText("SHOTS LEFT: ", 680, 763, 1.1, glm::vec3(0.0f, 0.0f, 0.0f)); // (0.0f, 0.0f, 1.0f - blue), (1.0f, 1.0f, 1.0f - white)
	m_pFont->RenderText("TIME LEFT: ", 7, 10, 1.1, glm::vec3(0.0f, 0.0f, 0.0f));

}


