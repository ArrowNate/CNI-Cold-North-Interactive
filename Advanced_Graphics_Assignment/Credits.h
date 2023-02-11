#ifndef _CREDITS_H
#define _CREDITS_H
#include "InputManager.h"
#include "Graphics.h"
#include "GameEntity.h"
#include "AudioManager.h"

class Credits : public GameEntity
{
private:
	Graphics* m_pGraphics;
	InputManager* m_pInputManager;
	AudioManager* m_pAudioManager;
	bool PlaySong;

<<<<<<< HEAD
	Font* m_pFont;
	Font* m_pFont2;

	Texture* m_pBackground;
=======
	Texture* m_pBackground;
	Texture* m_pGeorge;
	Texture* m_pRichard;
	Texture* m_pDaniel;
	Texture* m_pBrandon;
	Texture* m_pSam;
	Texture* m_pMikaelo;
	Texture* m_pMaksim;
	Texture* m_pPatrick;
>>>>>>> parent of 342c4a5 (Merge branch 'main' into Patrick)
	Texture* m_pLogo;

	int ScreenSelected;

public:
	Credits();
	~Credits();

	int SelectedScreen();

	void setSelectedScreen(int Screen);

	void Update();
	void Render();
};

#endif // !_CREDITS_H