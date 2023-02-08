#ifndef HUD_H
#include "Font.h"
#include <glm/glm.hpp>

class HUD
{

public:
	
	HUD();
	~HUD();

	void Update();
	void Render();

protected:
	Font* m_pFont;
};

#endif // !_HUD_H
