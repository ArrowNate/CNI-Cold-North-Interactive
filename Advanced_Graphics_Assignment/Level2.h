#ifndef LEVEL2_H
#define LEVEL2_H


#include "Level.h"

class Level2 : public Level
{
private:


	bool mInBounds;
	bool mOutBounds;
	

	

public:
	Level2();
	~Level2();

	void Update();
	void LateUpdate();
	void Render();

	bool HitBounds();

	float RandomMovement();
};

#endif // !LEVEL2_H