#ifndef COLLISION_H
#define COLLISION_H

#include "GameEntity.h"
class Collision : public GameEntity
{
protected:
	//bool collisionX;
	//bool collisionY;
	//bool collisionsZ;

	float clamp(float value, float min, float max);

public:
	bool CheckCollision(GameEntity* objectOne, GameEntity* objectTwo);
	bool CheckSphereCollision(GameEntity* objectOne, GameEntity* objectTwo);

	//void Collide(GameEntity objectOne, GameEntity objectTwo);
};

#endif // !COLLISION_H