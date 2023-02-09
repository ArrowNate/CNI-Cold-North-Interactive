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

	Texture* m_pBackground;
	Texture* m_pGeorge;
	Texture* m_pRichard;
	Texture* m_pDaniel;
	Texture* m_pBrandon;
	Texture* m_pSam;
	Texture* m_pMikaelo;
	Texture* m_pMaksim;
	Texture* m_pPatrick;
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