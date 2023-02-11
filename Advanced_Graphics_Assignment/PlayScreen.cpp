#include "PlayScreen.h"

PlayScreen::PlayScreen()
{
	m_pInputManager = InputManager::Instance();
	m_pAudioManager = AudioManager::Instance();
	m_pGraphics = Graphics::Instance();

	ScreenSelected = 1;

	m_pBackdrop = new Texture("Assets/Textures/CarnivalSetWaves.png", 1.0, 1.0, -1.0, -1.0, GL_RGBA);
}

PlayScreen::~PlayScreen()
{
	delete m_pBackdrop;
	m_pBackdrop = nullptr;
}

int PlayScreen::SelectedScreen()
{
	return ScreenSelected;
}

void PlayScreen::setSelectedScreen(int Screen)
{
	ScreenSelected = Screen;
}

void PlayScreen::Update()
{

	if (glfwGetKey(Graphics::Instance()->GetWindow(), GLFW_KEY_BACKSPACE) == GLFW_PRESS) {
		ScreenSelected = 2;
	}
}

void PlayScreen::Render()
{

	modelShader.Use();

	//----------------------THIS IS OUR VIEWPORT----------------------
	Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));

	glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
	glm::mat4 view = camera.GetViewMatrix();
	modelShader.SetMat4("projection", projection);
	modelShader.SetMat4("view", view);
	//----------------------THIS IS OUR VIEWPORT----------------------

	m_pStand->Render(mStand);
	m_pSpeaker->Render(mSpeaker);
	
	for (int i = 0; i < 15; i++) {
		m_pPlates[i]->Render(mPlates);
	}

	m_pHUD->Draw();

}