#ifndef _STARTSCREEN_H
#define _STARTSCREEN_H
#include "GameEntity.h"
//#include "Texture.h"
//#include "GameManager.h"
#include "Graphics.h"
#include "InputManager.h"
//#include "ScreenManager.h"

class StartScreen : public GameEntity
{
private:
	Graphics* m_pGraphics;
	InputManager* m_pInputManager;
	//Shader* m_pShader;
	//Font* m_pTestingFont;
	//Timer* m_pTimer;
	//InputManager* m_pInputManager;

	Texture* m_pBackground;
	Texture* m_pPlate;

	Texture* m_pCursor;
	Vector2 mCursorStartPos;
	Vector2 mCursorOffset;
	int mSelectedMode;

	Texture* m_pStartGame;

	Texture* m_pLogo;

public:
	StartScreen();
	~StartScreen();

	void ChangeSelectedMode(int change);

	int SelectedMode();

	void Update() override;
	void Render() override;
};

#endif // !_PLAYSCREEN_H