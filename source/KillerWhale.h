#pragma once
#include "Object.h"
#include "RenderManager.h"
#include "InputManager.h"
#include "Enemy.h"

enum StartState
{
	CELLING,
	FLOOR
};

class KillerWhale : public Enemy
{
	bool onFloor = CELLING;
public:

	KillerWhale(float posX, float posY, StartState startingState) : Enemy()
	{
		std::string texturePath = "resources/image.png";
		Vector2 size = { 1000, 1000 };
		Vector2 ofsset = { 0, 0 };
		_transform = new Transform();
		_renderer = new ImageRenderer(_transform, texturePath, ofsset, size);
		_physics = new RigidBody(_transform);
		Vector2 randomPosition = Vector2(rand() % RM->WINDOW_WIDTH, rand() % RM->WINDOW_HEIGHT);
		_transform->position = { posX, posY };
		_transform->scale = Vector2(0.5f, 0.5f);
		_transform->rotation = 0.f;

		_physics->AddCollider(new AABB(
			_transform->position,
			_transform->size * _transform->scale
		));
	}

	void Update() override;
	void Render() override;

	void Move() override;

};