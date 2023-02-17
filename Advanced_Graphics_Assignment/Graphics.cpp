#include "Graphics.h"

Graphics* Graphics::sInstance = nullptr;
bool Graphics::sInitialized = false;

Graphics* Graphics::Instance() { // singleton
		if (sInstance == nullptr) {
			sInstance = new Graphics();
		}

		return sInstance;
	};

void Graphics::Release() {
    delete sInstance;
    sInstance = nullptr;
    sInitialized = false;
}
	
bool Graphics::Init() {
    
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "PLATE OBLITERATOR", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

Graphics::Graphics()
{
    Init();
}

Graphics::~Graphics() {

    //AudioManager::Release(); // you call Release for shutting down the game
    //m_pAudioManager = nullptr;

    //ScreenManager::Release();
    //m_pScreenManager = nullptr;
}

GLFWwindow* Graphics::GetWindow()
{
    return window;
}
