#ifndef HUD_H
#include "Font.h"
#include <glm/glm.hpp>
#include "Texture.h"
#include "Timer.h"
#include "GameOverScreen.h"
#include "InputManager.h"

class HUD
{
public:
	HUD();
	~HUD();

	void Score();
	void DecreaseAmmo();

	int GetShots();
	int GetTime();

	void Update();
	void Draw();
	void DecreaseTimer();

	void Reset();

private:
	Texture* m_pHUDBorder;
	Font* m_pFont;
	HUD* m_pHUD;

	GameOverScreen* m_pGameOverScreen;

	int timeLeft;

	float previousTime = 0.0f;

	InputManager* m_pInputManager;

	int Point;
	int Shots;

};

#endif // !_HUD_H
