#ifndef PLAYSCREEN_H
#define PLAYSCREEN_H
#include "InputManager.h"
#include "HUD.h"
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
	Camera* m_pCamera;
	AudioManager* m_pAudioManager;
	InputManager* m_pInputManager;
	Graphics* m_pGraphics;

	int ScreenSelected;

	HUD* m_pHUD;
	Font* m_pFont;

	Model* m_pPlate;
	glm::mat4 mPlate;

	Model* m_pStand;
	glm::mat4 mStand;

	Model* m_pSpeaker;
	glm::mat4 mSpeaker;

	Shader modelShader;
	bool PlaySong;

	Model* m_pPlates[15];
	glm::mat4 mPlates;

	const unsigned int SCR_WIDTH = 1024;
	const unsigned int SCR_HEIGHT = 768;

	const float mPlatesx = -11;
	const int mPlatesz = -30;

public:
	PlayScreen();
	~PlayScreen();

	int SelectedScreen();

	void setSelectedScreen(int Screen);

	void Update();
	void Render();

};

#endif // !PLAYSCREEN_H