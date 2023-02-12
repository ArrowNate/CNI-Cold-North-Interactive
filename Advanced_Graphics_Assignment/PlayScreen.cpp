#include "PlayScreen.h"


PlayScreen::PlayScreen()
{

	//testing for objs
	m_pInputManager = InputManager::Instance();
    m_pAudioManager = AudioManager::Instance();
	m_pGraphics = Graphics::Instance();
	m_pCollision = new Collision();

    ScreenSelected = 1;

	PlaySong = true;
	mActive = false;
	mPlateActive = true;

	/*m_pCannon = new Model("Assets/Models/Pirate_Cannon.obj");
	m_pCannon->Position(-0.7f, -1.2f, 1.3);
	m_pCannon->ModelScale(-0.11f, -0.11f, -0.11f);*/

	m_pStand = new Model("Assets/Models/Stand.obj");
	m_pStand->Position(-1.1f, -4.5, -7);

	m_pSpeaker = new Model("Assets/Models/Speaker.obj");
	m_pSpeaker->Position(-6, -2.6, -8.7);


	/*m_pPlate = new Model("Assets/Models/Plate.obj");
	m_pPlate->Position(0, 0, -30);*/
	

	m_pBall = new Model("Assets/Models/Tennis_Ball.obj");
	//m_pBall->Position(m_pInputManager->getmousePosx(), m_pInputManager->getmousePosy(), 1);
	//m_pBall->Position( -0.7, -1.2f, 1.3);
	m_pBall->Position( 0, 0, 0);

	
	

	modelShader = Shader("Assets/Shaders/modelLoading.vs", "Assets/Shaders/modelLoading.fs");

	float y = 6;
	float temp = 0;

	for (int i = 0; i < 15; i++) { // first part is decleration, second part is the number of iterations/loops, third is to increment/move on, it can go to the opposite direction, can be different ways.
		m_pPlates[i] = new Model("Assets/Models/Plate.obj"); // extantiating variable, each element in the array
		m_pPlates[i]->Active(true);
		
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

	delete m_pCollision;
	m_pCollision = nullptr;

	m_pBall = nullptr;
    delete m_pBall;

    m_pCannon = nullptr;
    delete m_pCannon;

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
		std::cout << "x Position is: " << m_pSpeaker->Position().x << std::endl;
	}
	if (glfwGetKey(Graphics::Instance()->GetWindow(), GLFW_KEY_D) == GLFW_PRESS) {
		m_pSpeaker->Translate(Vector3(.1f, 0, 0));
		std::cout << "x Position is: " << m_pSpeaker->Position().x << std::endl;
	}
	if (glfwGetKey(Graphics::Instance()->GetWindow(), GLFW_KEY_W) == GLFW_PRESS) {
		m_pSpeaker->Translate(Vector3(0, .1f, 0));
		std::cout << "y Position is: " << m_pSpeaker->Position().y << std::endl;
	}
	if (glfwGetKey(Graphics::Instance()->GetWindow(), GLFW_KEY_S) == GLFW_PRESS) {
		m_pSpeaker->Translate(Vector3(0, -.1f, 0));
		std::cout << "y Position is: " << m_pSpeaker->Position().y << std::endl;
	}
	if (glfwGetKey(Graphics::Instance()->GetWindow(), GLFW_KEY_E) == GLFW_PRESS) {
		m_pSpeaker->ModelTranslate(0, 0, -.1f);
		std::cout << "z Position is: " << m_pSpeaker->Position().z << std::endl;
	}
	if (glfwGetKey(Graphics::Instance()->GetWindow(), GLFW_KEY_Q) == GLFW_PRESS) {
		m_pSpeaker->ModelTranslate(0, 0, 0.1f);
		std::cout << "z Position is: " << m_pSpeaker->Position().z << std::endl;
	}

	if (glfwGetKey(Graphics::Instance()->GetWindow(), GLFW_KEY_BACKSPACE) == GLFW_PRESS) {
		ScreenSelected = 2;

	}

	m_pHUD->Update();
	
	if (glfwGetKey(Graphics::Instance()->GetWindow(), GLFW_KEY_SPACE) == GLFW_PRESS) {
		mActive = true;
		std::cout << "SPACE" << std::endl;

		// moves the ball foward on keypress and controls speed
	}
		
	//m_pBall->Translate();

		//translate function for ball throw stop figure out how to write it ㅤ/ᐠ - ˕ -マ
		// plates are at -30 so the ball has to stop around there
}


void PlayScreen::LateUpdate() {

	//if (glfwGetKey(Graphics::Instance()->GetWindow(), GLFW_KEY_A) == GLFW_PRESS) {
	//		m_pBall->ModelTranslate(-0.05f, 0, 0);
	//		//m_pCannon->ModelTranslate(-0.05f, 0, 0);
	//		// making the cannon and ball move together
	//}

	//if (glfwGetKey(Graphics::Instance()->GetWindow(), GLFW_KEY_D) == GLFW_PRESS) {
	//		m_pBall->ModelTranslate(0.05f, 0, 0);
	//		//m_pCannon->ModelTranslate(0.05f, 0, 0);
	//		// making the cannon and ball move together
	//}
	
	if (mActive) 
	{
		
		m_pBall->ModelTranslate(m_pInputManager->getmousePosx(), m_pInputManager->getmousePosy(), -0.5);
		//m_pBall->ModelTranslate(0,0, -0.5);
		if (m_pBall->Position().z >= -35)
		{
			std::cout << m_pBall->Position().z << std::endl;
		}
	}
	else if (!mActive) {
		m_pBall->Position(-0.7f, -1.2f, 1.3);
		
	}

	if (m_pBall->Position().z <= -35)
	{
		mActive = false;
	}

	
	
	
	
	for (int i = 0; i < 15; i++) {
		

		if (m_pPlates[i]->Active()) {
			SphereCollide(m_pBall, m_pPlates[i]);
		}
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
		
		if (m_pPlates[i]->Active()) {
			m_pPlates[i]->Render(mPlates);
		}
	}

	if (mActive)
    {
    	m_pBall->Render(mBall);
    }

     m_pHUD->Draw();

	//m_pCannon->Render(mCannon);
}

void PlayScreen::Collide(GameEntity* objectOne, GameEntity* objectTwo) {
	
	if (objectTwo == nullptr) {
		std::cout << " m_pCollision is null" <<	std::endl;
		return;
	}

	if (m_pCollision->CheckCollision(objectOne, objectTwo)) {

		std::cout << " collion success" << std::endl;
	}

}

void PlayScreen::SphereCollide(GameEntity* objectOne, GameEntity* objectTwo) {

	if (mPlateActive) {

		if (m_pCollision->CheckSphereCollision(objectOne, objectTwo)) {
			std::cout << " collion success" << std::endl;
			m_pAudioManager->PlayMusic2("Assets/Music/PlateBreak.wav", false);
			
			objectTwo->Active(false);
			mActive = false;
		}
	}
}