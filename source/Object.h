#pragma once

#include "Vector2.h"
#include "Renderer.h"
#include "Transform.h"
#include <string>
#include <SDL3/SDL.h>
#include "RigidBody.h"

enum class ObjectType{PLAYER, BULLET, ENEMY, DEFAULT};

class Object
{
private:
	bool _isPendingDestroy = false;
protected:
	Transform* _transform;
	Renderer* _renderer = nullptr;
	RigidBody* _physics;
	ObjectType _type;

public:
	Object();

	virtual ~Object();

	virtual void Update();
	
	RigidBody* GetRigidBody();

	virtual void Render();

	Transform* GetTransform();

	ObjectType GetType()
	{
		return _type;
	}

	bool IsPendingDestroy() const;

	virtual void OnCollision(Object* other) {}

	virtual void Destroy();
};