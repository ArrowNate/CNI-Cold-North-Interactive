#ifndef HUD_H
#include "Font.h"
#include <glm/glm.hpp>
#include "Texture.h"
#include "InputManager.h"

class HUD
{
public:
	HUD();
	~HUD();

	void Score();
	void DecreaseAmmo();

	int GetShots();

	void Update();
	void Draw();

private:
	Texture* m_pHUDBorder;
	Font* m_pFont;
	HUD* m_pHUD;
	InputManager* m_pInputManager;

	int Point;
	int Shots;
};

#endif // !_HUD_H
