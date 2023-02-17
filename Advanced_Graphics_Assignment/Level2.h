#ifndef LEVEL2_H
#define LEVEL2_H


#include "Level.h"

class Level2 : public Level
{
private:


	bool mInBounds;
	bool mOutBounds;
	
	float randx = (rand() % 20 + -10) * 0.1;
	float randy = (rand() % 20 + -10) * 0.1;

	float velx = .1;
	float dirx = 1;

public:
	Level2();
	~Level2();

	void Update();
	void LateUpdate();
	void Render();

	float RandomMovement();
};

#endif // !LEVEL2_H