#ifndef _STARTSCREEN_H
#define _STARTSCREEN_H

#include "GameEntity.h"
#include "Graphics.h"

class StartScreen : public GameEntity
{
private:
	Graphics* m_pGraphics;
	//Shader* m_pShader;
	//Font* m_pTestingFont;

public:
	StartScreen();
	~StartScreen();

	void Update() override;
	void Render() override;
};

#endif // !_PLAYSCREEN_H