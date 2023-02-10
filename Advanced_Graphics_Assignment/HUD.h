#ifndef HUD_H
#define HUD_H
#include "Font.h"
#include <glm/glm.hpp>
#include "Texture.h"

class HUD
{

public:
	
	HUD();
	~HUD();

	void Update();
	void DecreaseTimer();
	void Draw();

private:
	Texture* m_pHUDBorder;
	Font* m_pFont;
	Font* m_pFont2;
	HUD* m_pHUD;

	int timeLeft;
};

#endif // !_HUD_H
