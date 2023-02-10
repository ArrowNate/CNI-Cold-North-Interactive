#include "PlayScreen.h"

Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));


PlayScreen::PlayScreen()
{
	m_pAudioManager = AudioManager::Instance();

	PlaySong = true;
	mActive = false;

	m_pBall = new Model("Assets/Models/Tennis_Ball.obj");
	m_pBall->Position(-0.07f, -0.2f, 0.9f);
	
	m_pCannon = new Model("Assets/Models/Pirate_Cannon.obj");
	m_pCannon->Position(-0.8f, -1.2f, -0.01f);

	modelShader = Shader("Assets/Shaders/modelLoading.vs", "Assets/Shaders/modelLoading.fs");
}

PlayScreen::~PlayScreen()
{
	m_pBall = nullptr;
	delete m_pBall;

	m_pCannon = nullptr;
	delete m_pCannon;

}

void PlayScreen::Update()
{
	/*if (PlaySong == true) {
		m_pAudioManager->PlayMusic2("Assets/Music/PlayScreenSong.mp3");
		PlaySong = false;
	}*/
	
	if (glfwGetKey(Graphics::Instance()->GetWindow(), GLFW_KEY_SPACE) == GLFW_PRESS) {
		mActive = true;
		std::cout << "SPACE" << std::endl;

		// moves the ball foward on keypress and controls speed
	}
		
	//m_pBall->Translate();

		//translate function for ball throw stop figure out how to write it ㅤ/ᐠ - ˕ -マ
		// plates are at -30 so the ball has to stop around there

	

	if (glfwGetKey(Graphics::Instance()->GetWindow(), GLFW_KEY_A) == GLFW_PRESS) {
			m_pBall->ModelTranslate(-0.05f, 0, 0);
			//m_pCannon->ModelTranslate(-0.05f, 0, 0);
			// making the cannon and ball move together
	}

	if (glfwGetKey(Graphics::Instance()->GetWindow(), GLFW_KEY_D) == GLFW_PRESS) {
			m_pBall->ModelTranslate(0.05f, 0, 0);
			//m_pCannon->ModelTranslate(0.05f, 0, 0);
			// making the cannon and ball move together
	}
	
	if (mActive) 
	{
		m_pBall->ModelTranslate(0, 0, -0.1f);
	}

	if (m_pBall->Position().z <= -35)
	{
		mActive = false;
	}
	std::cout << m_pBall->Position().z << std::endl;




}

void PlayScreen::Render()
{

	modelShader.Use();

	glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
	glm::mat4 view = camera.GetViewMatrix();
	modelShader.SetMat4("projection", projection);
	modelShader.SetMat4("view", view);

	if (mActive) 
	{
		m_pBall->Render(mBall);
	}

	
	m_pCannon->Render(mCannon);
	
	
	//m_pStand->Render(mStand);

}
