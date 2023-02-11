#ifndef PLAYSCREEN_H
#define PLAYSCREEN_H
#include "Graphics.h"
#include "InputManager.h"
#include "AudioManager.h"
#include "Font.h"
//#include "Shader.h"
//#include "Texture.h"
#include <iostream>
#include "Texture.h"

class PlayScreen : public GameEntity
{
private:
	Graphics* m_pGraphics;
	InputManager* m_pInputManager;
	AudioManager* m_pAudioManager;

	Texture* m_pBackdrop;

	int ScreenSelected;

public:
	PlayScreen();
	~PlayScreen();

	int SelectedScreen();

	void setSelectedScreen(int Screen);

	void Update();
	void Render();

};

#endif // !PLAYSCREEN_H