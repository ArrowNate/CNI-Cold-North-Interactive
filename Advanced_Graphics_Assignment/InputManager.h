#ifndef _INPUTMANAGER_H
#define _INPUTMANAGER_H
#include <GLFW/glfw3.h>
#include <iostream>

class InputManager
{
public:
	static InputManager* Instance();
	static InputManager* sInstance;

	GLFWwindow* window;

	static void Release();

	void mouseButtonCallBack(GLFWwindow* window, int button, int action, int mods);
	void cursorEnterCallback(GLFWwindow* window, int entered);
	void mouse_callback(GLFWwindow* window, double xPos, double yPos);
	void processInput(GLFWwindow* window);

	void Update();

	
private:

	InputManager();
	~InputManager();
	
};
 
#endif 
