#include "StartScreen.h"

StartScreen::StartScreen() {
	
	Shader ourShader("Assets/Shaders/text.vs", "Assets/Shaders/text.fs");
	m_pTestingFont->RenderText(ourShader, "(C) LearningOpen.com", 540.0f, 570.0f, 0.5f, glm::vec3(0.3, 0.7f, 0.9f));

}

StartScreen::~StartScreen() {

	//delete m_pTestingFont;
	//m_pTestingFont = nullptr;
}

void StartScreen::Update() {

}

void StartScreen::Render() {
	//m_pTestingFont->Render();
}