#include "Graphics.h"

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

Graphics* Graphics::sInstance = nullptr;

Graphics* Graphics::Instance() { // singleton
		if (sInstance == nullptr) {
			sInstance = new Graphics();
		}

		return sInstance;
	};

void FrameBufferSizeCallBack(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
	
bool Graphics::Init() {


		

	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Plate Obliterator", NULL, NULL);

	if (window == nullptr) {
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			return -1;
	}

	glfwMakeContextCurrent(window);
	//glfwSetFramebufferSizeCallback(window, FrameBufferSizeCallBack);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
			std::cout << "Failed to initialize GLAD" << std::endl;
			return -1;
	}


	glViewport(0, 0, 800, 600);

	while (!glfwWindowShouldClose(window))
	{
			// input
			// -----
			processInput(window);

			// render
			// ------
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
			// -------------------------------------------------------------------------------
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

void Graphics::Release() {
	delete sInstance;
	sInstance = nullptr;
	sInitialized = false;
}

bool Graphics::Initialized() {
	return sInitialized;
}