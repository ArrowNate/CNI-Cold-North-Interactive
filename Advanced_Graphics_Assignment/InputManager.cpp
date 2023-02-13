#include "InputManager.h"

InputManager* InputManager::sInstance = nullptr;

bool InputManager::getMouseButtonPressed = false;
//bool GameOverScreen::isGameOverScreen = false;

glm::vec2 InputManager::mousePos = glm::vec2(0, 0);

InputManager::InputManager()
{
	window = Graphics::Instance()->GetWindow();
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetMouseButtonCallback(window, mouseButtonCallBack);
	glfwSetCursor(window, glfwCreateStandardCursor(GLFW_CROSSHAIR_CURSOR));
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
	int screenWidth, screenHeight;
	glfwGetWindowSize(window, &screenWidth, &screenHeight);

	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);

		mousePos.x = xpos / (screenWidth / 2) - 1;
		mousePos.y = (screenHeight - ypos) / (screenHeight / 2) - 1; // This code gives us the proper coords between the range we need which is between -1 and 1
		
		system("CLS");
		std::cout << "\nX:" << mousePos.x; "\n";
		std::cout << "\nY:" << mousePos.y; "\n\n";
		
		
		if (mousePos.x >= -0.5 && mousePos.x <= 0.5 && mousePos.y >= -0.5 && mousePos.y <= -0.01) // This is for the button location but on all screens.
		{
			InputManager::returnToMainMenu();
		}
	}
	else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
	{
		getMouseButtonPressed = false;
	}
}

void InputManager::returnToMainMenu() {
	/*exit(0);*/
}

void InputManager::mouse_callback(GLFWwindow* window, double xPos, double yPos)
{
	//std::cout << xPos << ":" << yPos << std::endl;
	mousePos.x = xPos;
	mousePos.y = yPos;
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

glm::vec2 InputManager::getmousePos()
{
	return mousePos;
}

bool InputManager::MouseButtonPressed()
{
	return getMouseButtonPressed;
}


