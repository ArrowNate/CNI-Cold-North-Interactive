#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>


namespace OpenGLFramework {
	class Graphics
	{
		
		//GLFWwindow* window;
		static Graphics* sInstance;

	public:
		Graphics();
		~Graphics();

		static Graphics* Instance();
		static void Release();
		static bool Initialized();

		void FrameBufferSizeCallBack(GLFWwindow* window, int width, int height);
		void processInput(GLFWwindow* window);

		const unsigned int SCR_WIDTH = 800;
		const unsigned int SCR_HEIGHT = 600;

		virtual bool Init();
	};
}


