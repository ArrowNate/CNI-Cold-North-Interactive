#ifndef HUD_H
#include "Font.h"
#include <glm/glm.hpp>
#include "Texture.h"

class HUD
{

public:
	HUD();
	~HUD();

	void Update();
	void Draw();

private:
	Texture* m_pHUDBorder;
	Font* m_pFont;
	HUD* m_pHUD;
};

#endif // !_HUD_H
