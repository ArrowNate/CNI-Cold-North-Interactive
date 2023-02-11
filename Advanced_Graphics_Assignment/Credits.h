#ifndef _CREDITS_H
#define _CREDITS_H
#include "InputManager.h"
#include "Graphics.h"
#include "GameEntity.h"
#include "AudioManager.h"
#include "Font.h"

class Credits : public GameEntity
{
private:
	Graphics* m_pGraphics;
	InputManager* m_pInputManager;
	AudioManager* m_pAudioManager;
	bool PlaySong;

	Font* m_pFont;
	Font* m_pFont2;

	Texture* m_pBackground;
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