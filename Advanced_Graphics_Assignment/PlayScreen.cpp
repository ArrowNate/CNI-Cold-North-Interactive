#include "PlayScreen.h"

Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));


PlayScreen::PlayScreen()
{
	m_pAudioManager = AudioManager::Instance();

	PlaySong = true;

	//m_pTest = new Model("Assets/Models/skull3.obj");
	m_pStand = new Model("Assets/Models/Stand.obj");
	m_pStand->Position(-1.1f, -4.5, -7);

	m_pPlate = new Model("Assets/Models/Plate.obj");
	m_pPlate->Position(-1.1f, -1, -30);

	m_pSpeaker = new Model("Assets/Models/Speaker.obj");
	m_pSpeaker->Position(-6.5f, -3, -10);

	modelShader = Shader("Assets/Shaders/modelLoading.vs", "Assets/Shaders/modelLoading.fs");
}

PlayScreen::~PlayScreen()
{
	//delete m_pBackdrop;
	//m_pBackdrop = nullptr;
}

void PlayScreen::Update()
{
	if (PlaySong == true) {
		//m_pAudioManager->PlayMusic2("Assets/Music/PlayScreenSong.mp3");
		m_pAudioManager->PlayMusic3D("Assets/Music/PlayScreenSong.mp3", -2.0f, -3, 1);
		PlaySong = false;
	}

	if (glfwGetKey(Graphics::Instance()->GetWindow(), GLFW_KEY_A) == GLFW_PRESS) {
		m_pSpeaker->Translate(Vector3( - .1f, 0, 0));
		std::cout << m_pSpeaker->Position().x << std::endl;
		//m_pTest->Translate(-Vec3_Right * 0.1, World);
	}
	if (glfwGetKey(Graphics::Instance()->GetWindow(), GLFW_KEY_D) == GLFW_PRESS) {
		m_pSpeaker->Translate(Vector3(.1f, 0, 0));
		std::cout << m_pSpeaker->Position().x << std::endl;
	}
	if (glfwGetKey(Graphics::Instance()->GetWindow(), GLFW_KEY_W) == GLFW_PRESS) {
		m_pSpeaker->Translate(Vector3(0, .1f, 0));
		std::cout << m_pSpeaker->Position().y << std::endl;
	}
	if (glfwGetKey(Graphics::Instance()->GetWindow(), GLFW_KEY_S) == GLFW_PRESS) {
		m_pSpeaker->Translate(Vector3(0, -.1f, 0));
		std::cout << m_pSpeaker->Position().y << std::endl;
	}
	if (glfwGetKey(Graphics::Instance()->GetWindow(), GLFW_KEY_E) == GLFW_PRESS) {
		m_pPlate->ModelTranslate(0, 0, -.1f);
		std::cout << "EEEEEEEEEEEEE" << std::endl;
	}
	if (glfwGetKey(Graphics::Instance()->GetWindow(), GLFW_KEY_Q) == GLFW_PRESS) {
		m_pPlate->ModelTranslate(0, 0, 0.1f);
		std::cout << "EEEEEEEEEEEEE" << std::endl;
	}
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
	
	//m_pTest->Render(testname);
	m_pStand->Render(mStand);
	m_pPlate->Render(mPlate);
	m_pSpeaker->Render(mSpeaker);
}
