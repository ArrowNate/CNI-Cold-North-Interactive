#ifndef _INPUTMANAGER_H
#define _INPUTMANAGER_H
#include "Graphics.h"
//#include "GameOverScreen.h"

class InputManager : GameEntity
{
public:

	InputManager();
	~InputManager();
	
	static InputManager* Instance();
	static InputManager* sInstance;

	static void Release();

	static void mouseButtonCallBack(GLFWwindow* window, int button, int action, int mods);
	//static void mouseButtonCallBack2(GameEntity* window, int button, int action, int mods);
	static void mouse_callback(GLFWwindow* window, double xPos, double yPos);
	//static void mouse_callback2(GameEntity* game, double xPos, double yPos);
	void processInput(GLFWwindow* window);
	

	glm::vec2 getmousePos();
	//float getmousePos2();
	float getmousePosx();
	float getmousePosy();

	

	

	static bool MouseButtonPressed();

	void Update();

	
	//glm::vec3 viewToWorldCoordTransform(int mouse_x, int mouse_y);
	//glm::vec3 getRayFromScreenSpace(const glm::vec2& pos);

	static void returnToMainMenu();


private:
	GLFWwindow* window;

	static bool getMouseButtonPressed;

	static glm::vec2 mousePos;
};
 
#endif 