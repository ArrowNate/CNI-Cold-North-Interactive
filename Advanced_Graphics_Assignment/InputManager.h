#ifndef _INPUTMANAGER_H
#define _INPUTMANAGER_H
#include "Graphics.h"

class InputManager
{
public:
	static InputManager* Instance();
	static InputManager* sInstance;

	GLFWwindow* window;

	static void Release();

	static void mouseButtonCallBack(GLFWwindow* window, int button, int action, int mods);
	static void cursorEnterCallBack(GLFWwindow* window, int entered);
	static void mouse_callback(GLFWwindow* window, double xPos, double yPos);
	void processInput(GLFWwindow* window);


	void Update();

	
private:

	InputManager();
	~InputManager();
	
};
 
#endif 
