#ifndef _INPUTMANAGER_H
#define _INPUTMANAGER_H
#include "Graphics.h"

class InputManager
{
public:
	InputManager();
	~InputManager();
	
	static InputManager* Instance();
	static InputManager* sInstance;

	static void Release();

	static void mouseButtonCallBack(GLFWwindow* window, int button, int action, int mods);
	//static void cursorEnterCallBack(GLFWwindow* window, int entered);
	static void mouse_callback(GLFWwindow* window, double xPos, double yPos);
	void setCrosshairCursor(GLFWcursor* cursor);
	void processInput(GLFWwindow* window);
	
	glm::vec2 getmousePos();

	static bool MouseButtonPressed();

	void Update();
	
	
private:
	GLFWwindow* window;
	GLFWcursor* crosshair_cursor;
	
	static bool getMouseButtonPressed;

	static glm::vec2 mousePos;
	
};
 
#endif 
