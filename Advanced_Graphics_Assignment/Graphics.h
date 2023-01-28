#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>



	class Graphics
	{
		
		//GLFWwindow* window;
		static Graphics* sInstance;

	public:
		//Graphics();
		//~Graphics();

		static Graphics* Instance();
		static void Release();
		static bool sInitialized;
		static bool Initialized();

		void FrameBufferSizeCallBack(GLFWwindow* window, int width, int height);
		void processInput(GLFWwindow* window);

		

		virtual bool Init();
	};



