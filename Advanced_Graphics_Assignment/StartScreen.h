#ifndef _STARTSCREEN_H
#define _STARTSCREEN_H

#include "GameEntity.h"

class StartScreen
{
private:
	int mSelectedMode;
public:
	StartScreen();
	~StartScreen();

	void ChangeSelectedMode(int change);
	int SelectedMode();

	void Update();
	void Render();
};

#endif // !_PLAYSCREEN_H