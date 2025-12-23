#pragma once
#include "Object.h"
#include "RigidBody.h"
#include "RenderManager.h"
#include "InputManager.h"
#include "ImageRenderer.h"

class Bullet : public Object
{
public:
	Bullet(Vector2 playerPosition) : Object()
	{
		std::string texturePath = "resources/image.png";
		Vector2 size = { 1000, 1000 };
		Vector2 ofsset = { 0, 0 };
		_transform = new Transform();
		_renderer = new ImageRenderer(_transform, texturePath, ofsset, size);
		_physics = new RigidBody(_transform);
		_type = ObjectType::BULLET;
		
		Vector2 randomPosition = Vector2(rand() % RM->WINDOW_WIDTH, rand() % RM->WINDOW_HEIGHT);
		_transform->position = { playerPosition };
		_transform->scale = Vector2(0.1f, 0.1f);
		_transform->rotation = 0.f;

		_physics->AddCollider(new AABB(
			_transform->position,
			_transform->size * _transform->scale
		));

		_physics->SetVelocity(Vector2(600.f, 0.f));
	}

	void Update() override;
	void Render() override;

};
