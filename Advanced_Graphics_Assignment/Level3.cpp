#include "Level3.h"

Level3::Level3()
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

	m_pStand = new Model("Assets/Models/Level3.obj");
	m_pStand->Position(0.11f, -1.1, 1.6);

	m_pSpeaker = new Model("Assets/Models/NewSpeaker.obj");
	m_pSpeaker->Position(-4.5, -3.2, -7.0); // Mikaelo speaker--> m_pSpeaker->Position(-6, -4.4, -8.7);

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

Level3::~Level3()
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

	m_pCannon = nullptr;
	delete m_pCannon;
}

void Level3::Update()
{
	m_pHUD->Update();
	//float mRandVelx = (rand() % -2 + 1 * .1);
	for (int i = 0; i < mMaxPlates; i++) {

		if (i % 3 == 0) {
			velx = 0.2;
		}

		if (i % 4 == 0) {
			vely = 0.2;
		}

		if (m_pPlates[i]->Position().x >= 13.5)
		{
			std::cout << "Hitting Plates Bounds" << std::endl;
			m_pPlates[i]->HitBounds(true);
		}
		else if (m_pPlates[i]->Position().x <= -13.5) {
			m_pPlates[i]->HitBounds(false);
		}

		if (m_pPlates[i]->Position().y >= 8)
		{
			std::cout << "Hitting Plates Bounds" << std::endl;
			m_pPlates[i]->HitBounds(true);
		}
		else if (m_pPlates[i]->Position().y <= -8) {
			m_pPlates[i]->HitBounds(false);
		}

		if (m_pPlates[i]->HitBounds()) {
			m_pPlates[i]->ModelTranslate(velx * dirx * -2, vely * diry * -1, 0);
		}
		else if (!m_pPlates[i]->HitBounds()) {
			m_pPlates[i]->ModelTranslate(velx * dirx * 2, vely * diry * 1, 0);
		}

		/*if (glfwGetKey(Graphics::Instance()->GetWindow(), GLFW_KEY_A) == GLFW_PRESS) {
			m_pPlates[i]->Translate(Vector3(-.1f, 0, 0));
			std::cout << "x Position is: " << m_pPlates[i]->Position().x << std::endl;
		}
		if (glfwGetKey(Graphics::Instance()->GetWindow(), GLFW_KEY_D) == GLFW_PRESS) {
			m_pPlates[i]->Translate(Vector3(.1f, 0, 0));
			std::cout << "x Position is: " << m_pPlates[i]->Position().x << std::endl;
		}
		if (glfwGetKey(Graphics::Instance()->GetWindow(), GLFW_KEY_W) == GLFW_PRESS) {
			m_pPlates[i]->Translate(Vector3(0, .1f, 0));
			std::cout << "y Position is: " << m_pPlates[i]->Position().y << std::endl;
		}
		if (glfwGetKey(Graphics::Instance()->GetWindow(), GLFW_KEY_S) == GLFW_PRESS) {
			m_pPlates[i]->Translate(Vector3(0, -.1f, 0));
			std::cout << "y Position is: " << m_pPlates[i]->Position().y << std::endl;
		}
		if (glfwGetKey(Graphics::Instance()->GetWindow(), GLFW_KEY_E) == GLFW_PRESS) {
			m_pPlates[i]->ModelTranslate(0, 0, -.1f);
			std::cout << "z Position is: " << m_pPlates[i]->Position().z << std::endl;
		}
		if (glfwGetKey(Graphics::Instance()->GetWindow(), GLFW_KEY_Q) == GLFW_PRESS) {
			m_pPlates[i]->ModelTranslate(0, 0, 0.1f);
			std::cout << "z Position is: " << m_pPlates[i]->Position().z << std::endl;
		}*/
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

void Level3::Render()
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

void Level3::LateUpdate()
{
	for (int i = 0; i < mMaxPlates; i++) {

		if (m_pPlates[i]->Active()) {
			SphereCollide(m_pBall, m_pPlates[i]);
		}
	}
}
