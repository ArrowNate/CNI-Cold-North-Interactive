#ifndef PLAYSCREEN_H
#define PLAYSCREEN_H
#include "Font.h"
#include <iostream>
//#include "HUD.h"

class PlayScreen
{
private:
	
	/*Font* m_pFont;
	HUD* m_pHUD;*/

public:

	PlayScreen();
	~PlayScreen();

	void Update();
	void Render();

};
#endif // !PLAYSCREEN_H
