#include "PlayScreen.h"

Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));


PlayScreen::PlayScreen()
{
	m_pAudioManager = AudioManager::Instance();

	PlaySong = true;

	m_pTest = new Model("Assets/Models/Tennis_Ball.obj");

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

	if (glfwGetKey(Graphics::Instance()->GetWindow(), GLFW_KEY_A) == GLFW_PRESS) {
		m_pTest->ModelTranslate(-.1f, 0, 0);
		std::cout << "AAAAAAAAAAAAAA" << std::endl;
		//m_pTest->Translate(-Vec3_Right * 0.1, World);
	}

	//if (glfwGetKey(Graphics::Instance()->GetWindow(), GLFW_KEY_SPACE == GLFW_PRESS))
	//{
	//	//this function wants to make the ball launch forward
	//	//moving the z axis would move the object back and forth
	//	//
	//}




}

void PlayScreen::Render()
{

	modelShader.Use();

	glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
	glm::mat4 view = camera.GetViewMatrix();
	modelShader.SetMat4("projection", projection);
	modelShader.SetMat4("view", view);



	/*glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
	model = glm::scale(model, glm::vec3(0.1f, 0.1f, 0.1f));
	modelShader.SetMat4("model", model);
	m_pTest->Draw(modelShader);*/

	m_pTest->Render(testname);
	//m_pStand->Render(mStand);

}
