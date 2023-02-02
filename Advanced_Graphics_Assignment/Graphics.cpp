#include "Graphics.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

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

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "PLATE OBLITERATOR", NULL, NULL);
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

    //Remember to delete and nullptr the pointers!
    //----------TEXTURE EXAMPLE-------------------------------

    m_pStartScreen = new StartScreen();
    m_pAudioManager = AudioManager::Instance();
    
    //m_pBackground = new Texture("Assets/Textures/CarnvialBackgroundSet.jpg", .3, .3, .3, -.3, -.3, -.3, -.3, .3, GL_RGB);

    //m_pTesting = new Texture("Assets/Textures/CarnivalSetWaves.png", .3, .3, .3, -.3, -.3, -.3, -.3, .3, GL_RGBA);
    ////Testing->Parent(this); // Parent not working yet
    //m_pTesting->Position(Vector3(1000, 800)); // this does not work yet either

    //m_pMoose = new Texture("Assets/Textures/Moose3.jpg", .75, .75, .75, .25, -.25, .25, -.25, .75, GL_RGB);

    //----------TEXTURE EXAMPLE-------------------------------
    
    //----------AUDIO EXAMPLE-------------------------------
    m_pAudioManager->PlayMusic();
    //----------AUDIO EXAMPLE-------------------------------
    
    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //----------TEXTURE EXAMPLE-------------------------------
        //m_pTesting->Draw();
        //m_pMoose->Draw();
        m_pStartScreen->Render();
        
        //m_pBackground->Draw();

        //----------TEXTURE EXAMPLE-------------------------------

        

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

Graphics::~Graphics() {
    //delete m_pTesting;
    //m_pTesting = nullptr;

    //delete m_pMoose;
    //m_pMoose = nullptr;

    AudioManager::Release();
    m_pAudioManager = nullptr;

    delete m_pStartScreen;
    m_pStartScreen = nullptr;

    //delete m_pBackground;
    //m_pBackground = nullptr;
}
