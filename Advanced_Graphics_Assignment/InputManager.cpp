#include "InputManager.h"

InputManager* InputManager::sInstance = nullptr;

bool InputManager::getMouseButtonPressed = false;

glm::vec2 InputManager::mousePos = glm::vec2(0, 0);

//glm::vec2 InputManager::mousePos2 = glm::vec2(0, 0);

//float xClip = (mousePos.x + 0.5f) / 320.0f - 1.0f;
//float yClip = 1.0f - (mousePos.y + 0.5f) / 240.0f;



InputManager::InputManager()
{
	window = Graphics::Instance()->GetWindow();
	glfwSetCursorPosCallback(window, mouse_callback);
	//glfwSetMouseButtonCallback(window, mouseButtonCallBack);
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

	float xClip = ((mousePos.x + 0.5f) / 1024) * 2.0f - 1.0f;
	float yClip = 1.0f - ((mousePos.y + 0.5f) / 768) * 2.0f;

	if (button == GLFW_MOUSE_BUTTON_LEFT  == GLFW_PRESS)
	{
		//getMouseButtonPressed = true;
		std::cout << "Left button press" << std::endl;
		std::cout << xClip << std::endl;
		std::cout << yClip << std::endl;
	}
	else if (button == GLFW_MOUSE_BUTTON_LEFT == GLFW_RELEASE)
	{
		getMouseButtonPressed = false;
	}
}

//void InputManager::mouseButtonCallBack2(GameEntity* window, int button, int action, int mods) {
//	if (button == GLFW_MOUSE_BUTTON_LEFT == GLFW_PRESS)
//	{
//		//getMouseButtonPressed = true;
//		std::cout << "Left button press" << std::endl;
//		std::cout << mousePos2.x << std::endl;
//		std::cout << mousePos2.y << std::endl;
//	}
//	else if (button == GLFW_MOUSE_BUTTON_LEFT == GLFW_RELEASE)
//	{
//		getMouseButtonPressed = false;
//	}
//}

void InputManager::mouse_callback(GLFWwindow* window, double xPos, double yPos)
{
	//std::cout << xPos << ":" << yPos << std::endl;
	mousePos.x = xPos;
	mousePos.y = yPos;
}

//void InputManager::mouse_callback2(GameEntity* game, double xPos, double yPos) 
//{
//	mousePos2.x = xPos;
//	mousePos2.y = yPos;
//}

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

float InputManager::getmousePosx()
{
	float xClip = ((mousePos.x + 0.5f) / 1024) * 2.0f - 1.0f;
	
	return xClip;
}

float InputManager::getmousePosy()
{
	
	float yClip = 1.0f - ((mousePos.y + 0.5f) / 768) * 2.0f;
	return yClip;
}

bool InputManager::MouseButtonPressed()
{
	return getMouseButtonPressed;

}


//glm::vec3 InputManager::viewToWorldCoordTransform(int mouse_x, int mouse_y) {
//	// NORMALISED DEVICE SPACE
//	double x = 2.0 * mouse_x / WINDOW_WIDTH - 1;
//	double y = 2.0 * mouse_y / WINDOW_HEIGHT - 1;
//	// HOMOGENEOUS SPACE
//	glm::vec4 screenPos = glm::vec4(x, -y, -1.0f, 1.0f);
//	// Projection/Eye Space
//	glm::mat4 ProjectView = GlobalProjection * GlobalView;
//	glm::mat4 viewProjectionInverse = inverse(ProjectView);
//	glm::vec4 worldPos = viewProjectionInverse * screenPos;
//	return glm::vec3(worldPos);
//}
//
//glm::vec3 InputManager::getRayFromScreenSpace(const glm::vec2& pos)
//{
//	glm::mat4 invMat = inverse(m_glData.getPerspective() * m_glData.getView());
//	glm::vec4 near = glm::vec4((pos.x - Constants::m_halfScreenWidth) / Constants::m_halfScreenWidth, -1 * (pos.y - Constants::m_halfScreenHeight) / Constants::m_halfScreenHeight, -1, 1.0);
//	glm::vec4 far = glm::vec4((pos.x - Constants::m_halfScreenWidth) / Constants::m_halfScreenWidth, -1 * (pos.y - Constants::m_halfScreenHeight) / Constants::m_halfScreenHeight, 1, 1.0);
//	glm::vec4 nearResult = invMat * near;
//	glm::vec4 farResult = invMat * far;
//	nearResult /= nearResult.w;
//	farResult /= farResult.w;
//	glm::vec3 dir = glm::vec3(farResult - nearResult);
//	return normalize(dir);
//
//
//}

