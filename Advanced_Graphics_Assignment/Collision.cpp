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



//bool Collision::CheckSphereCollision(GameEntity* objectOne, GameEntity* objectTwo,  float oneRadius,  float twoRadius)
//{
//		glm::vec3 center(objectOne->Position().x + oneRadius);
//
//		glm::vec3 aabb_half_extents(objectTwo->Scale().x / 2.0f, objectTwo->Scale().y / 2.0f, objectTwo->Scale().z / 2.0f);
//		glm::vec3 aabb_center(
//			objectTwo->Position().x + aabb_half_extents.x,
//			objectTwo->Position().y + aabb_half_extents.y,
//			objectTwo->Position().z + aabb_half_extents.z);
//
//		// get difference vector between both centers
//		glm::vec3 difference = center - aabb_center;
//		glm::vec3 clamped = glm::clamp(difference, -aabb_half_extents, aabb_half_extents);
//		// add clamped value to AABB_center and we get the value of box closest to circle
//		glm::vec3 closest = aabb_center + clamped;
//		// retrieve vector between center circle and closest point AABB and check if length <= radius
//		difference = closest - center;
//		return glm::length(difference) < oneRadius;
//}

bool Collision::CheckSphereCollision(GameEntity* objectOne, GameEntity* objectTwo) 
{
	//I honestly ripped this off youtube, hopefully richard can explain whats happening?

	float xDiff = (objectOne->Position().x - objectTwo->Position().x) * (objectOne->Position().x - objectTwo->Position().x);
	float yDiff = (objectOne->Position().y - objectTwo->Position().y) * (objectOne->Position().y - objectTwo->Position().y);
	float zDiff = (objectOne->Position().z - objectTwo->Position().z) * (objectOne->Position().z - objectTwo->Position().z);

	float sumOfDiff = xDiff + yDiff + zDiff;

	if (sqrt(sumOfDiff) <= 1.2) {
		return true;
	}

	return false;
}