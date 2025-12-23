#pragma once
#include "Object.h"
#include "RenderManager.h"
#include "InputManager.h"
#include "Enemy.h"

class Circler : public Enemy
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


	Circler(float posX, float posY) : Enemy()
	{
		std::string texturePath = "resources/image.png";
		Vector2 size = { 1000, 1000 };
		Vector2 ofsset = { 0, 0 };
		_transform = new Transform();
		_renderer = new ImageRenderer(_transform, texturePath, ofsset, size);
		_physics = new RigidBody(_transform);
		Vector2 randomPosition = Vector2(rand() % RM->WINDOW_WIDTH, rand() % RM->WINDOW_HEIGHT);
		_transform->position = { posX, posY };
		_transform->scale = Vector2(1.f, 1.f);
		_transform->rotation = 0.f;
		_transform->size = size;
		_type = ObjectType::ENEMY;

		_physics->AddCollider(new AABB(
			_transform->position,
			_transform->size * _transform->scale
		));

		center = { posX, posY };
		oldPosY = posY;
		radius = 100.f;
		speed = 0.05f;
		angle = 0.f;
	}

	void Update() override;
	void Render() override;

	void Move() override;
	void EnterInScene(int targetPosX) override;
	void ExitOutScene() override;

};