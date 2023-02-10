#include "GameEntity.h"

GameEntity::GameEntity(float x, float y, float z)
	: mPosition(x, y), mRotation(0.0f), mScale(Vec3_One), mActive(true), mParent(nullptr) {
}

GameEntity::GameEntity(const Vector3& position)
	: mPosition(position), mRotation(0.0f), mScale(Vec3_One), mActive(true), mParent(nullptr) {
}


GameEntity::~GameEntity() {
	mParent = nullptr;
}

void GameEntity::Position(float x, float y, float z) {
	mPosition = Vector3(x, y, z);
}

void GameEntity::Position(const Vector3& pos) {
	mPosition = pos;
}

Vector3 GameEntity::Position(Space space) {
	if (space == Local || mParent == nullptr) {
		return mPosition;
	}
	Vector3 parentScale = mParent->Scale(World);
	Vector3 rotPosition = RotateVector(mPosition, mParent->Rotation(Local));

	return mParent->Position(World) + Vector3(rotPosition.x * parentScale.x, rotPosition.y * parentScale.y, rotPosition.z * parentScale.z);
}

void GameEntity::Rotation(float rot) {
	mRotation = rot;

	while (mRotation > 360.0f) {
		mRotation -= 360.0f;
	}

	while (mRotation < 0.0f) {
		mRotation += 360.0f;
	}
}

float GameEntity::Rotation(Space space) {
	if (space == Local || mParent == nullptr) {
		return mRotation;
	}

	return mParent->Rotation(World) + mRotation;
}

void GameEntity::Scale(Vector3 scale) {
	mScale = scale;
}

Vector3 GameEntity::Scale(Space space) {
	if (space == Local || mParent == nullptr) {
		return mScale;
	}

	Vector3 scale = mParent->Scale(World);
	scale.x *= mScale.x;
	scale.y *= mScale.y;
	scale.z *= mScale.z;

	return scale;
}

void GameEntity::Active(bool active) {
	mActive = active;
}

bool GameEntity::Active() const {
	return mActive;
}

void GameEntity::Parent(GameEntity* parent) {
	if (parent == nullptr) {
		mPosition = Position(World);
		mRotation = Rotation(World);
		mScale = Scale(World);
	}
	else {
		if (mParent != nullptr) {
			Parent(nullptr);
		}
		Vector3 parentScale = parent->Scale(World);

		mPosition = RotateVector(Position(World) - parent->Position(World), -parent->Rotation(World));
		mPosition.x /= parentScale.x;
		mPosition.y /= parentScale.y;
		mPosition.z /= parentScale.z;

		mRotation -= parent->Rotation(World);
		mScale = Vector3(mScale.x / parentScale.x, mScale.y / parentScale.y, mScale.z / parentScale.z);
	}

	mParent = parent;
}

GameEntity* GameEntity::Parent() const
{
	return mParent;
}

void GameEntity::Translate(Vector3 vec, Space space) {
	if (space == World) {
		mPosition += vec;
	}
	else {
		mPosition += RotateVector(vec, Rotation());
	}
}

void GameEntity::Rotate(float amount) {
	Rotation(mRotation + amount);
}