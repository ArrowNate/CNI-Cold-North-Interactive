#ifndef _BALL_H
#define _BALL_H
#include "GameEntity.h"
#include "InputManager.h"
#include "MathHelper.h"
#include <iostream>

class Ball : public GameEntity
{
private:
	
	InputManager* m_pInput;

	float mMoveSpeed;

	void Movement();

	int Velocity;
	int DirectionX;
	int DirectionY;

public:

Ball();
~Ball();

void Update();
void Render();




};

#endif // !_BALL_H