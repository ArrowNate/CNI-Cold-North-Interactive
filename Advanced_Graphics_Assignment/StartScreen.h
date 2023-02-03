#ifndef _STARTSCREEN_H
#define _STARTSCREEN_H

#include "GameEntity.h"
#include "Graphics.h"
#include "InputManager.h"

class StartScreen : public GameEntity
{
private:
	Graphics* m_pGraphics;
	InputManager* m_pInputManager;
	//Shader* m_pShader;
	//Font* m_pTestingFont;

public:
	StartScreen();
	~StartScreen();

	void Update() override;
	void Render() override;
};

#endif // !_PLAYSCREEN_H