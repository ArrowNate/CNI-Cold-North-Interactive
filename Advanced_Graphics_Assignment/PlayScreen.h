#ifndef PLAYSCREEN_H
#define PLAYSCREEN_H
//#include "Graphics.h"
//#include "Font.h"
//#include "Shader.h"
//#include "Texture.h"
#include <iostream>
#include <assimp/camera.h>

#include "AudioManager.h"
#include "Camera.h"
#include "Model.h"
#include "Graphics.h"

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class PlayScreen : public GameEntity
{
private:
	Camera m_pCamera;
	//Texture* m_pBackdrop;
	AudioManager* m_pAudioManager;

	Model* m_pBall;
	glm::mat4 mBall;

	Model* m_pCannon;
	glm::mat4 mCannon;

	Shader modelShader;
	bool PlaySong;

	const unsigned int SCR_WIDTH = 800;
	const unsigned int SCR_HEIGHT = 600;
	
	bool mActive;


	
public:
	PlayScreen();
	~PlayScreen();

	void Update();
	void Render();

};
#endif // !PLAYSCREEN_H
