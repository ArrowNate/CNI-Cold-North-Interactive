#ifndef HUD_H
#include "Font.h"
#include <glm/glm.hpp>
#include "Texture.h"
#include "Timer.h"
#include "GameOverScreen.h"

class HUD
{

public:
	
	HUD();
	~HUD();

	void Update();
	void Draw();
	void DecreaseTimer();

private:
	Texture* m_pHUDBorder;
	Font* m_pFont;
	HUD* m_pHUD;
	GameOverScreen* m_pGameOverScreen;

	int timeLeft;

	float previousTime = 0.0f;
};

#endif // !_HUD_H
