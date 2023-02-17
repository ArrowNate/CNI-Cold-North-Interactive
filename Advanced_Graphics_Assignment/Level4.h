#ifndef LEVEL4_H
#define LEVEL4_h

#include "Level.h"

class Level4 : public Level
{
private:


	bool mInBounds;
	bool mOutBounds;


	float velx = .1;
	float dirx = 1;

public:
	Level4();
	~Level4();

	void Update();
	void LateUpdate();
	void Render();

	bool HitBounds();

	float RandomMovement();
};


#endif // !LEVEL4_H
