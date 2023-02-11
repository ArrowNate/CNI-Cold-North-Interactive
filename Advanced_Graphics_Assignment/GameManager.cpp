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
	if (Graphics::Instance()->GetWindow() == NULL) {
		std::cout << "IT'S NULL" << std::endl;
		return;
	}

	while (!glfwWindowShouldClose(Graphics::Instance()->GetWindow()))
	{
		Update();
		LateUpdate();
		Render();

		glfwPollEvents();
	}
}

void GameManager::Update() {
	m_pScreenManager->Update();
}

void GameManager::LateUpdate()
{
	m_pScreenManager->LateUpdate();
}

void GameManager::Render() {
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);	// First
	glClear(GL_COLOR_BUFFER_BIT);			// Second
	m_pScreenManager->Render();
	//m_pGraphics->Render();
	glfwSwapBuffers(Graphics::Instance()->GetWindow()); // Last
}

GameManager::GameManager() {
	m_pGraphics = Graphics::Instance();

	m_pScreenManager = ScreenManager::Instance();

	m_pAudioManager = AudioManager::Instance();

	m_pInputManager = InputManager::Instance();
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