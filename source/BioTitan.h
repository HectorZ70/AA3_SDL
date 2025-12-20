#pragma once
#include "Object.h"
#include "RenderManager.h"
#include "InputManager.h"
#include "Enemy.h"
#include "BUllet.h"
#include "Spawner.h"


class BioTitan : public Enemy
{
	int health = 10;
	int frameTime = 50;
	int currentFrame = 0;

public:

	BioTitan() : Enemy()
	{
		std::string texturePath = "resources/image.png";
		Vector2 size = { 100000, 100000 };
		Vector2 ofsset = { 0, 0 };
		_transform = new Transform();
		_renderer = new ImageRenderer(_transform, texturePath, ofsset, size);
		_physics = new RigidBody(_transform);
		Vector2 randomPosition = Vector2(rand() % RM->WINDOW_WIDTH, rand() % RM->WINDOW_HEIGHT);
		_transform->position = { 1080.f, 1090.f };
		_transform->scale = Vector2(size);
		_transform->rotation = 0.f;
		_type = ObjectType::ENEMY;

		_physics->AddCollider(new AABB(
			_transform->position,
			_transform->size * _transform->scale
		));
	}

	void Update() override;
	void Render() override;
	void Shoot();
	void Damage();
	void Die();

};