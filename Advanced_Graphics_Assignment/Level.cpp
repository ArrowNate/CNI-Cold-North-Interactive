#include "Level.h"


Level::Level()
{
	m_pInputManager = InputManager::Instance();
	m_pAudioManager = AudioManager::Instance();
	m_pGraphics = Graphics::Instance();
	m_pCollision = new Collision();
	m_pHUD = new HUD();
	m_pTimer = Timer::Instance();

	PlaySong = true;
	mActive = false;
	mReloaded = true;
	mLevelOver = false;
	mNoAmmo = false;

	/*m_pCannon = new Model("Assets/Models/Pirate_Cannon.obj");
	m_pCannon->Position(-0.6f, -1.2f, 1.3);
	m_pCannon->ModelScale(-0.11f, -0.11f, -0.11f);*/

	m_pStand = new Model("Assets/Models/BasicStand2.obj");
	m_pStand->Position(-0.9f, -1.0f, 1.29f);

	m_pSpeaker = new Model("Assets/Models/NewSpeaker.obj");
	m_pSpeaker->Position(-4.5, -3.0, -7.0);

	m_pBall = new Model("Assets/Models/Tennis_Ball.obj");
	m_pBall->Position(mBallStartx, mBallStarty, mBallStartz);

	modelShader = Shader("Assets/Shaders/modelLoading.vs", "Assets/Shaders/modelLoading.fs");

	for (int i = 0; i < mMaxPlates; i++) { // first part is decleration, second part is the number of iterations/loops, third is to increment/move on, it can go to the opposite direction, can be different ways.
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

		if (mLevelReset = false) {
			//m_pPlates[i]->Active(true);
			std::cout << " Plates reset" << std::endl;
		}

		
		temp++;
	}
}

Level::~Level()
{
	delete m_pHUD;
	m_pHUD = nullptr;

	AudioManager::Release();
	m_pAudioManager = nullptr;

	InputManager::Release();
	m_pInputManager = nullptr;

	Graphics::Release();
	m_pGraphics = nullptr;

	Timer::Release();
	m_pTimer = nullptr;

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

	/*m_pCannon = nullptr;
	delete m_pCannon;*/
}





void Level::Update()
{
	m_pHUD->Update();

	if (m_pHUD->GetTime() == 0) {
		mLevelOver = true;
		
	}

	if (PlaySong == true) {
		m_pAudioManager->PlayMusic3D("Assets/Music/WindmillHut.mp3", -5, 0, 0);
		PlaySong = false;
	}

	Shoot();

	BallMovement();

	
	/*if (glfwGetKey(Graphics::Instance()->GetWindow(), GLFW_KEY_A) == GLFW_PRESS) {
		m_pStand->Translate(Vector3(-.1f, 0, 0));
		std::cout << "x Position is: " << m_pStand->Position().x << std::endl;
	}
	if (glfwGetKey(Graphics::Instance()->GetWindow(), GLFW_KEY_D) == GLFW_PRESS) {
		m_pStand->Translate(Vector3(.1f, 0, 0));
		std::cout << "x Position is: " << m_pStand->Position().x << std::endl;
	}
	if (glfwGetKey(Graphics::Instance()->GetWindow(), GLFW_KEY_W) == GLFW_PRESS) {
		m_pStand->Translate(Vector3(0, .1f, 0));
		std::cout << "y Position is: " << m_pStand->Position().y << std::endl;
	}
	if (glfwGetKey(Graphics::Instance()->GetWindow(), GLFW_KEY_S) == GLFW_PRESS) {
		m_pStand->Translate(Vector3(0, -.1f, 0));
		std::cout << "y Position is: " << m_pStand->Position().y << std::endl;
	}
	if (glfwGetKey(Graphics::Instance()->GetWindow(), GLFW_KEY_E) == GLFW_PRESS) {
		m_pStand->ModelTranslate(0, 0, -.1f);
		std::cout << "z Position is: " << m_pStand->Position().z << std::endl;
	}
	if (glfwGetKey(Graphics::Instance()->GetWindow(), GLFW_KEY_Q) == GLFW_PRESS) {
		m_pStand->ModelTranslate(0, 0, 0.1f);
		std::cout << "z Position is: " << m_pStand->Position().z << std::endl;
	}*/

}

void Level::LateUpdate() 
{

	for (int i = 0; i < mMaxPlates; i++) {

		if (m_pPlates[i]->Active()) {
			SphereCollide(m_pBall, m_pPlates[i]);
		}
	}

}

void Level::Render()
{
	glDisable(GL_CULL_FACE);
	modelShader.Use();
	//----------------------THIS IS OUR VIEWPORT----------------------
	Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));

	glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
	glm::mat4 view = camera.GetViewMatrix();
	modelShader.SetMat4("projection", projection);
	modelShader.SetMat4("view", view);
	//----------------------THIS IS OUR VIEWPORT----------------------

	m_pStand->Render(mStand);

	glEnable(GL_CULL_FACE);
	m_pSpeaker->Render(mSpeaker);
	glDisable(GL_CULL_FACE);

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

void Level::Collide(GameEntity* objectOne, GameEntity* objectTwo) {

	if (objectTwo == nullptr) {
		std::cout << " m_pCollision is null" << std::endl;
		return;
	}

	if (m_pCollision->CheckCollision(objectOne, objectTwo)) {

		std::cout << " collion success" << std::endl;
	}

}

void Level::SphereCollide(GameEntity* objectOne, GameEntity* objectTwo) {

	if (m_pCollision->CheckSphereCollision(objectOne, objectTwo)) {
		//std::cout << " collion success" << std::endl;
		//m_pAudioManager->PlayMusic2("Assets/Music/PlateBreak.wav", false);
		m_pAudioManager->PlayMusic3D("Assets/Music/PlateBreak.wav", objectTwo->Position().x, objectTwo->Position().y, -1, false);

		objectOne->Active(false);
		objectTwo->Active(false);
		mActive = false;
		mReloaded = true;
		m_pHUD->Score();
		m_pHUD->DecreaseAmmo();
	}
}

void Level::Reset() {
	
	mLevelReset = true;
	m_pHUD->Reset();
	for (int i = 0; i < mMaxPlates; i++) {
			m_pPlates[i]->Active(true);
			//std::cout << " Plates reset" << std::endl;
	}
	PlaySong = true;
	mLevelOver = false;
	mNoAmmo = false;
	m_pAudioManager->PauseMusic();
}

bool Level::GetLevelOver() {
	return mLevelOver;
}

bool Level::GetNoAmmo() {
	return mNoAmmo;
}

void Level::Shoot() 
{

	if (m_pHUD->GetShots() >= mMinAmmo) {
		if (glfwGetKey(Graphics::Instance()->GetWindow(), GLFW_KEY_SPACE) == GLFW_PRESS) {

			if (mReloaded) {
				mActive = true;
				mControl = true;
				mReloaded = false;
				mDir* mDirForwad;
				//m_pBall = new Model("Assets/Models/Tennis_Ball.obj");
				m_pBall->Position(mBallStartx, mBallStarty, mBallStartz);

			}
			//std::cout << "SPACE" << std::endl;
		}
	}
	else {
		mNoAmmo = true;
		//std::cout << "NO AMMO" << std::endl;
	}
}

void Level::BallMovement() 
{
	if (mActive)
	{
		if (!mControl) {
			mDir* mDirBack;
			m_pBall->ModelTranslate(mDropVelx, mDropVely, mDropVelz);
		}
		else if (mControl = true) {
			m_pBall->ModelTranslate(m_pInputManager->getmousePosx() * mDir, m_pInputManager->getmousePosy() * mDir, mBallzVel * mDir);
		}

		if (m_pBall->Position().z >= mBallFrontBounds) {

			mActive = false;
			mReloaded = true;
			m_pHUD->DecreaseAmmo();
		}

		if (m_pBall->Position().y <= mBallyBounds) {

			mActive = false;
			mReloaded = true;
			m_pHUD->DecreaseAmmo();
		}

		if (m_pBall->Position().z <= mBallBoardBounds) {
			mControl = false;
			m_pAudioManager->PlayMusic3D("Assets/Music/Thud.wav", m_pBall->Position().x, m_pBall->Position().y, 0, false);
			//std::cout << " ball should turn" << std::endl;
		}
	}
	else if (!mActive) {
		m_pBall->Position(mBallStartx, mBallStarty, mBallStartz);
	}
}