#include "Level2.h"

Level2::Level2() 
{
	m_pInputManager = InputManager::Instance();
	m_pAudioManager = AudioManager::Instance();
	m_pGraphics = Graphics::Instance();
	m_pCollision = new Collision();
	m_pHUD = new HUD();

	m_pStand = new Model("Assets/Models/Stand.obj");
	m_pStand->Position(-1.1f, -4.5, -7);

	m_pSpeaker = new Model("Assets/Models/Speaker.obj");
	m_pSpeaker->Position(-6, -2.6, -8.7);

	m_pBall = new Model("Assets/Models/Tennis_Ball.obj");
	m_pBall->Position(mBallStartx, mBallStarty, mBallStartz);

	modelShader = Shader("Assets/Shaders/modelLoading.vs", "Assets/Shaders/modelLoading.fs");

	for (int i = 0; i < mMaxPlates; i++) { // first part is decleration, second part is the number of iterations/loops, third is to increment/move on, it can go to the opposite direction, can be different ways.
		m_pPlates[i] = new Model("Assets/Models/Plate.obj"); // extantiating variable, each element in the array
		m_pPlates[i]->Active(true);
		m_pPlates[i]->HitBounds(false);
		
		
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

		if (mLevelReset = false) {
			//m_pPlates[i]->Active(true);
			std::cout << " Plates reset" << std::endl;
		}

		m_pPlates[i]->ModelTranslate(0, 11, 0);
		temp++;
	}

	
}

Level2::~Level2() {

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

void Level2::Update() {
	m_pHUD->Update();


	for (int i = 0; i < mMaxPlates; i++) {

		if (m_pPlates[i]->Position().x >= 13.5)
		{
			std::cout << "Hitting Plates Bounds" << std::endl;
			m_pPlates[i]->HitBounds(true);
		}
		else if (m_pPlates[i]->Position().x <= -13.5) {
			m_pPlates[i]->HitBounds(false);
		}

		if (m_pPlates[i]->HitBounds()) {
			m_pPlates[i]->ModelTranslate(velx * dirx * -1, 0, 0);
		}
		else if (!m_pPlates[i]->HitBounds()) {
			m_pPlates[i]->ModelTranslate(velx * dirx * 1, 0, 0);
		}
	}

	if (m_pHUD->GetTime() == 0) {
		mLevelOver = true;

	}

	if (mLevelOver == true) {
		std::cout << "Should go to game over" << std::endl;
	}


	if (PlaySong == true) {
		m_pAudioManager->PlayMusic3D("Assets/Music/WindmillHut.mp3", -5, 0, 0);
		PlaySong = false;
	}

	Shoot();

	BallMovement();
}

void Level2::LateUpdate() {
	for (int i = 0; i < mMaxPlates; i++) {

		if (m_pPlates[i]->Active()) {
			SphereCollide(m_pBall, m_pPlates[i]);
		}
	}
}

void Level2::Render() {
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

	for (int i = 0; i < mMaxPlates; i++) {

		if (m_pPlates[i]->Active()) {
			m_pPlates[i]->Render(mPlates);
		}
	}

	if (mActive)
	{
		m_pBall->Render(mBall);
	}

	//m_pCannon->Render(mCannon);

	m_pHUD->Draw();
}

//float Level2::RandomMovement() {
	
	//return randx;
//}