#include "HUD.h"

HUD::HUD() {
	m_pFont = new Font();
}

HUD::~HUD() {
	delete m_pFont;
	m_pFont = nullptr;
}

void HUD::Update() {

}

void HUD::Render() {

	const int thickness = 2;

	for (int i = -thickness; i <= thickness; ++i)
	{
		for (int j = -thickness; j <= thickness; ++j)
		{
			if (i == 0 && j == 0)
			{
				continue;
			}

			// border color
			m_pFont->RenderText("SCORE: ", 7 + i, 763 + j, 1.1, glm::vec3(1.0f, 1.0f, 1.0f));
			m_pFont->RenderText("SHOTS LEFT: ", 680 + i, 763 + j, 1.1, glm::vec3(1.0f, 1.0f, 1.0f));
			m_pFont->RenderText("TIME LEFT: ", 7 + i, 10 + j, 1.1, glm::vec3(1.0f, 1.0f, 1.0f));
		}
	}

	// font color
	m_pFont->RenderText("SCORE: ", 7, 763, 1.1, glm::vec3(0.0f, 0.0f, 0.0f));
	m_pFont->RenderText("SHOTS LEFT: ", 680, 763, 1.1, glm::vec3(0.0f, 0.0f, 0.0f));
	m_pFont->RenderText("TIME LEFT: ", 7, 10, 1.1, glm::vec3(0.0f, 0.0f, 0.0f));

}


