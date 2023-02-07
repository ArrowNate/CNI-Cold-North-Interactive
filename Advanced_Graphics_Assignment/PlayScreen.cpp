#include "PlayScreen.h"

Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));


PlayScreen::PlayScreen()
{
	m_pAudioManager = AudioManager::Instance();

	PlaySong = true;

	m_pTest = new Model("Assets/Models/skull3.obj");
	
	modelShader = Shader("Assets/Shaders/modelLoading.vs", "Assets/Shaders/modelLoading.fs");
}

PlayScreen::~PlayScreen()
{
	//delete m_pBackdrop;
	//m_pBackdrop = nullptr;
}

void PlayScreen::Update()
{
	/*if (PlaySong == true) {
		m_pAudioManager->PlayMusic2("Assets/Music/PlayScreenSong.mp3");
		PlaySong = false;
	}*/

	

	


}

void PlayScreen::Render()
{
	
	modelShader.Use();

	glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
	glm::mat4 view = camera.GetViewMatrix();
	modelShader.SetMat4("projection", projection);
	modelShader.SetMat4("view", view);

	

	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
	model = glm::scale(model, glm::vec3(0.1f, 0.1f, 0.1f));
	modelShader.SetMat4("model", model);
	m_pTest->Draw(modelShader);
	


}
