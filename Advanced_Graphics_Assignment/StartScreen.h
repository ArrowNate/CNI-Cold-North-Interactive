#ifndef _STARTSCREEN_H
#define _STARTSCREEN_H
#include "GameEntity.h"
//#include "Texture.h"
//#include "GameManager.h"
#include "Graphics.h"
#include "InputManager.h"
#include "AudioManager.h"
#include "Font.h"
//#include "ScreenManager.h"

class StartScreen : public GameEntity
{
private:

	double previousTime = 0.0;

	//enum Screens { Start, Credits };
	Graphics* m_pGraphics;
	InputManager* m_pInputManager;
	AudioManager* m_pAudioManager;
	bool PlaySong;

	Texture* m_pBackground;
	Texture* m_pLogo;
	Texture* m_pStartGame;
	Texture* m_pCredits;
	Texture* m_pArrow;
	Texture* m_pArrow2;

	int ScreenSelected;

	Font* m_pFont;
	Font* m_pFont2;

public:
	StartScreen();
	~StartScreen();

	void ChangeSelectedMode(int change);
	
	int SelectedMode();
	int SelectedScreen();

	void setSelectedScreen(int Screen);

	void Update() override;
	void Render() override;
};

#endif // !_PLAYSCREEN_H