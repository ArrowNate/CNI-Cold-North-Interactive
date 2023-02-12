#ifndef HUD_H
#include "Font.h"
#include <glm/glm.hpp>
#include "Texture.h"
#include "Timer.h"

class HUD
{

public:
	
	HUD();
	~HUD();

	void Update();
	void Draw();
	void DecreaseTime();

private:
	Texture* m_pHUDBorder;
	Font* m_pFont;
	HUD* m_pHUD;

	Timer* m_pTimer;

	int timeLeft;
};

#endif // !_HUD_H
