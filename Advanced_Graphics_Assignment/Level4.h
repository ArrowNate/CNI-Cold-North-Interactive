#ifndef LEVEL4_H
#define LEVEL4_H

#include "Level.h"

class Level4 : public Level
{
private:

	float velx = .1;
	float dirx = 1;

public:
	Level4();
	~Level4();

	void Update();
	void LateUpdate();
	void Render();
};


#endif // !LEVEL4_H
