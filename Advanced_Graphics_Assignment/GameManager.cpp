#include "GameManager.h"

GameManager* GameManager::sInstance = nullptr;

GameManager* GameManager::Instance()
{
	if (sInstance == nullptr) {
		sInstance = new GameManager();
	}
	return sInstance;
}
void GameManager::Release() {
	delete sInstance;
	sInstance = nullptr;
}

void GameManager::Run() {

	while (!glfwWindowShouldClose(Graphics::Instance()->GetWindow()))
	{
		// input
		// -----
		//processInput(Graphics::Instance()->GetWindow());
		//m_pScreenManager->Update();
		// render
		// ------
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//----------TEXTURE EXAMPLE-------------------------------
		m_pScreenManager->Render();
		//m_pBackground->Draw();


		//----------TEXTURE EXAMPLE-------------------------------



		glfwSwapBuffers(Graphics::Instance()->GetWindow());
		glfwPollEvents();
	}
}

void GameManager::Update() {
	/*mScreenManager->Update();*/
}

void GameManager::LateUpdate()
{
}

void GameManager::Render() {
	//mGraphics->ClearBackBuffer();
	//mScreenManager->Render();
	//mGraphics->Render();
}

GameManager::GameManager() {
	m_pGraphics = Graphics::Instance();

	/*mAssetManager = AssetManager::Instance();

	mTimer = Timer::Instance();

	mScreenManager = ScreenManager::Instance();*/
}

GameManager::~GameManager() {
	//ScreenManager::Release();
	//mScreenManager = nullptr;

	/*Timer::Release();
	mTimer = nullptr;*/

	/*AssetManager::Release();
	mAssetManager = nullptr;*/

	Graphics::Release();
	m_pGraphics = nullptr;

	glfwTerminate();
}

void GameManager::processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

//GLFWwindow* GameManager::GetWindow()
//{
//	return window;
//}