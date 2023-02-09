#include "InputManager.h"

InputManager::InputManager()
{
	window = Graphics::Instance()->GetWindow();
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetMouseButtonCallback(window, mouseButtonCallBack);
	glfwSetCursorEnterCallback(window, cursorEnterCallBack);
}

InputManager::~InputManager()
{
}

InputManager* InputManager::Instance()
{
	if (sInstance == nullptr)
	{
		sInstance = new InputManager();
	}
	return sInstance;
}

void InputManager::Release()
{
	delete sInstance;
	sInstance = nullptr;
}


void InputManager::mouseButtonCallBack(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT  == GLFW_PRESS)
	{
		std::cout << "Left button press" << std::endl;
	}
	
}

void InputManager::cursorEnterCallBack(GLFWwindow* window, int entered)
{
	if (entered)
	{
		std::cout << "Entered Window" << std::endl;
	}
	else
	{
		std::cout << "Left Window" << std::endl;
	}
}

void InputManager::mouse_callback(GLFWwindow* window, double xPos, double yPos)
{
	std::cout << xPos << ":" << yPos << std::endl;
}

void InputManager::processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
	
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		std::cout << "W was pressed" << std::endl;
	}
		
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		std::cout << "S was pressed" << std::endl;
	}
		
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		std::cout << "A was pressed" << std::endl;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		std::cout << "D was pressed" << std::endl;
	}
}

void InputManager::Update()
{
	
}

InputManager* InputManager::sInstance = nullptr;

/*unsigned char pixels[16 * 16 * 4];
	memset(pixels, 0xff, sizeof(pixels));
	GLFWimage image;
	image.width = 16;
	image.height = 16;
	image.pixels;
	GLFWcursor* cursor = glfwCreateCurser(&image, 0, 0);
	glfwSetCursor(window, cursor);*/

//glfwSetFramebufferSizeCallback(pWindow, FrameBufferSizeCallBack);
