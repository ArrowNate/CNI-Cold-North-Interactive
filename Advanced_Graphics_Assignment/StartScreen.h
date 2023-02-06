#ifndef _STARTSCREEN_H
#define _STARTSCREEN_H
#include "GameEntity.h"
//#include "Texture.h"
//#include "GameManager.h"
#include "Graphics.h"
#include "InputManager.h"
#include "AudioManager.h"
//#include "ScreenManager.h"

class StartScreen : public GameEntity
{
private:
	Graphics* m_pGraphics;
	InputManager* m_pInputManager;
	AudioManager* m_pAudioManager;
	bool PlaySong;
	//Shader* m_pShader;
	//Font* m_pTestingFont;
	//Timer* m_pTimer;

	Texture* m_pBackground;
	Texture* m_pPlate;
	Texture* m_pStartGame;
	Texture* m_pLogo;
	Texture* m_pCursor;

	GameEntity* m_pTopBar;

	Vector2 mCursorStartPos;
	Vector2 mCursorOffset;
	int mSelectedMode;

	

public:
	StartScreen();
	~StartScreen();

	void ChangeSelectedMode(int change);

	int SelectedMode();

	void Update() override;
	void Render() override;
};

#endif // !_PLAYSCREEN_H