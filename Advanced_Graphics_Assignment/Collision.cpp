#include "Collision.h"

bool Collision::CheckCollision(GameEntity* objectOne, GameEntity* objectTwo) {

	bool collisionX = objectOne->Position().x + objectOne->Scale().x >=
					  objectTwo->Position().x &&
					  objectTwo->Position().x + objectTwo->Scale().x >=
					  objectOne->Position().x;

	bool collisionY = objectOne->Position().y + objectOne->Scale().y >=
				   	  objectTwo->Position().y &&
					  objectTwo->Position().y + objectTwo->Scale().y >=
					  objectOne->Position().y;

	bool collisionZ = objectOne->Position().z + objectOne->Scale().z >=
					  objectTwo->Position().z &&
					  objectTwo->Position().z + objectTwo->Scale().z >=
					  objectOne->Position().z;

	return (collisionX && collisionY && collisionZ);
}

//void Collision::Collide(GameEntity objectOne, GameEntity objectTwo)
//{
//	if (CheckCollision(objectOne, objectTwo)) {
//
//	}
//}