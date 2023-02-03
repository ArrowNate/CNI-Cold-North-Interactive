#include "InputManager.h"

InputManager::InputManager()
{
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
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		std::cout << "Left button press" << std::endl;
	}
}

void InputManager::cursorEnterCallback(GLFWwindow* window, int entered)
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
	std::cout << xPos << " : " << yPos << std::endl;
}

void InputManager::processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		// command for pressing W
	}
		
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		// command for pressing S
	}
		
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		// command for pressing A
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		// command for pressing D
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
	GLFWcursor* cursor = glfwCreatCurser(&image, 0, 0);
	glfwSetCursor(window, cursor);*/