#include "PlayScreen.h"
#include <iostream>
#include <chrono>
#include <thread>


PlayScreen::PlayScreen()
{

	//testing for objs
	m_pInputManager = InputManager::Instance();
    m_pAudioManager = AudioManager::Instance();
	m_pGraphics = Graphics::Instance();

    ScreenSelected = 1;

	PlaySong = true;

	m_pStand = new Model("Assets/Models/Stand.obj");
	m_pStand->Position(-1.1f, -4.5, -7);

	m_pSpeaker = new Model("Assets/Models/Speaker.obj");
	m_pSpeaker->Position(-6.5f, -3, -10);

	modelShader = Shader("Assets/Shaders/modelLoading.vs", "Assets/Shaders/modelLoading.fs");

	float y = 6;
	float temp = 0;

	for (int i = 0; i < 15; i++) { // first part is decleration, second part is the number of iterations/loops, third is to increment/move on, it can go to the opposite direction, can be different ways.
		m_pPlates[i] = new Model("Assets/Models/Plate.obj"); // extantiating variable, each element in the array

		if (i % 5 == 0) {// if the remainder of the division is 0
			y = y - 3.5;
			temp = 0;
		} 

		if (i != 0) {
			m_pPlates[i]->Position(mPlatesx + (temp * 5.25), y, mPlatesz);

		}
		else {
			m_pPlates[i]->Position(mPlatesx, y, mPlatesz);
		}
		temp++;
	}

	m_pHUD = new HUD();
}

PlayScreen::~PlayScreen()
{
	delete m_pHUD;
	m_pHUD = nullptr;

	AudioManager::Release();
	m_pAudioManager = nullptr;

	InputManager::Release();
	m_pInputManager = nullptr;

	Graphics::Release();
	m_pGraphics = nullptr;

	delete m_pStand;
	m_pStand = nullptr;

	for (auto l : m_pPlates) {
		delete l;
		l = nullptr;
	}

	delete m_pSpeaker;
	m_pSpeaker = nullptr;

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

	if (PlaySong == true) {
		m_pAudioManager->PlayMusic3D("Assets/Music/PlayScreenSong.mp3", -2.0f, -3, 1);
		PlaySong = false;
	}

	if (glfwGetKey(Graphics::Instance()->GetWindow(), GLFW_KEY_A) == GLFW_PRESS) {
		m_pSpeaker->Translate(Vector3( - .1f, 0, 0));
		std::cout << m_pSpeaker->Position().x << std::endl;
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
		m_pSpeaker->ModelTranslate(0, 0, -.1f);
		std::cout << "EEEEEEEEEEEEE" << std::endl;
	}
	if (glfwGetKey(Graphics::Instance()->GetWindow(), GLFW_KEY_Q) == GLFW_PRESS) {
		m_pSpeaker->ModelTranslate(0, 0, 0.1f);
		std::cout << "EEEEEEEEEEEEE" << std::endl;
	}

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

