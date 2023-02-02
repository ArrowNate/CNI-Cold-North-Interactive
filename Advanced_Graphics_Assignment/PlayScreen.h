#ifndef PLAYSCREEN_H
#define PLAYSCREEN_H
#include "Graphics.h"
#include "Font.h"
#include "Shader.h"

#include "Texture.h"

#include <iostream>
class PlayScreen
{
private:
	Texture* m_pBackdrop;

public:
	PlayScreen();
	~PlayScreen();

	void Update();
	void Render();


};
#endif // !PLAYSCREEN_H
