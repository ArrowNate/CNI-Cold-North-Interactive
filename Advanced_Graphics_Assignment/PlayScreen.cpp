#include "PlayScreen.h"
#include "HUD.h"


PlayScreen::PlayScreen()
{
	m_pFont = new Font();
}

PlayScreen::~PlayScreen()
{
	delete m_pFont;
	m_pFont = nullptr;
}

void PlayScreen::Update()
{

}

void PlayScreen::Render()
{
	// This is a nested loop to make a white boarder around the text to help it stand out a bit better.

	const int thickness = 2;  // This controls the thickness of the white boarder

	for (int i = -thickness; i <= thickness; ++i) {
		for (int j = -thickness; j <= thickness; ++j) {  // The purpose of this loop is to repeat the code inside the loop a certain number of times, determined by                                                  thickness, which should end the loop.
			if (i == 0 && j == 0) {
				continue; // we include this because if i and j = 0 then there is no offset for a border thus it would not be required so why render it.
			}

			// border color
			m_pFont->RenderText("SCORE: ", 7 + i, 763 + j, 1.1, glm::vec3(1.0f, 1.0f, 1.0f));
			m_pFont->RenderText("SHOTS LEFT: ", 680 + i, 763 + j, 1.1, glm::vec3(1.0f, 1.0f, 1.0f));
			m_pFont->RenderText("TIME LEFT: ", 7 + i, 10 + j, 1.1, glm::vec3(1.0f, 1.0f, 1.0f));
		}
	}

	// font color
	m_pFont->RenderText("SCORE: ", 7, 763, 1.1, glm::vec3(0.0f, 0.0f, 0.0f)); // (1.0f,0.7f,0.0f - b.orange), (1.0f, 0.0f, 0.0f - red), (0.0f, 0.7f, 1.0f - b.blue)
	m_pFont->RenderText("SHOTS LEFT: ", 680, 763, 1.1, glm::vec3(0.0f, 0.0f, 0.0f)); // (0.0f, 0.0f, 1.0f - blue), (1.0f, 1.0f, 1.0f - white)
	m_pFont->RenderText("TIME LEFT: ", 7, 10, 1.1, glm::vec3(0.0f, 0.0f, 0.0f));
}
