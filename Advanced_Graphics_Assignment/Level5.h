#ifndef LEVEL5_H
#define LEVEL5_H

#include "Level.h"
class Level5 : public Level
{
private:




	float velx = .1;
	float dirx = 1;

public:
	Level5();
	~Level5();

	void Update();
	void LateUpdate();
	void Render();


};

#endif // !LEVEL5_H