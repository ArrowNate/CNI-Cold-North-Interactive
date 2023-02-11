#ifndef STARTSCREEN_H
#define STARTSCREEN_H
#include "GameEntity.h"
#include "Graphics.h"
#include "InputManager.h"
#include "AudioManager.h"
#include "Timer.h"
class SplashScreen : public GameEntity
{
private:
	Graphics* m_pGraphics;
	InputManager* m_pInputManager;
	AudioManager* m_pAudioManager;
	Timer* m_pTimer;
	Texture* m_pLogo;
	float mSplashTotalTime;
	float mSplashTimer;
	bool mSplashDone;
	bool PlayIntro;
	int ScreenSelected;


public:
	SplashScreen();
	~SplashScreen();

	int SelectedMode();
	int SelectedScreen();

	void setSelectedScreen(int Screen);

	void Update() override;
	void Render() override;
};

#endif