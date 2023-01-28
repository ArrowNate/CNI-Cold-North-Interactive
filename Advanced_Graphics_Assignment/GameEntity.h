#ifndef _GAMEENTITY_H
#define _GAMEENTITY_H

#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "MathHelper.h"

// There is already a glm::vec3 data type

class GameEntity
{
public:

	enum Space { Local = 0, World = 1 };

private:
	Vector3 mPosition;
	float mRotation;
	Vector3 mScale;

	bool mActive;
	GameEntity* mParent;

public:
	GameEntity(float x = 0.0f, float y = 0.0f, float z = 0.0f);
	GameEntity(float x = 0.0f, float y = 0.0f); // might delete, dont know if we need.
	GameEntity(const Vector3& position);
	GameEntity(const Vector2& position);// might delete, dont know if we need.
	~GameEntity();

	void Position(float x, float y, float z);
	void Position(float x, float y); // might delete, dont know if we need.
	void Position(const Vector3& pos);
	Vector3 Position(Space space = World);

	void Rotation(float rot);
	float Rotation(Space space = World);

	void Scale(Vector3 scale);
	Vector3 Scale(Space space = World);

	void Active(bool active);
	bool Active() const;

	void Parent(GameEntity* parent);
	GameEntity* Parent() const;

	void Translate(Vector3 vec, Space space = Local);
	void Rotate(float amount);

	virtual void Update() {};
	virtual void Render() {};
};

#endif