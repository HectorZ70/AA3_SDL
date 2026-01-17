#pragma once
#include "ImageObject.h"
#include "RenderManager.h"
#include "InputManager.h"
#include "ImageRenderer.h"

class Enemy : public ImageObject
{
	bool finishEnter = false;
	bool finishCircle = false;
	int numberOfTimes = 0;
public:
	Vector2 center;
	float radius;
	float speed;
	float angle;

	float oldPosY;

	std::string texturePath = "resources/image.png";
	Vector2 size = { 128, 128 };
	Vector2 offset = { 0,0 };

	Enemy() : ImageObject(texturePath, offset, size)
	{
		_type = ObjectType::ENEMY;

		_renderer = new ImageRenderer(_transform, texturePath, offset, size);

		_transform->size = size;
		_transform->scale = { 1.0f, 1.0f };

		_physics->AddCollider(new AABB(
			_transform->position,
			_transform->size * _transform->scale
		));
	}

	virtual void Move() {}
	virtual void EnterInScene(int targetPosX) {}
	virtual void ExitOutScene() {}
	virtual void OnCollision(Object* other);
};
