#ifndef PLAYSCREEN_H
#define PLAYSCREEN_H
#include "Font.h"
#include <iostream>

class PlayScreen
{
private:
	
	Font* m_pFont;

public:

	PlayScreen();
	~PlayScreen();

	void Update();
	void Render();

};
#endif // !PLAYSCREEN_H
