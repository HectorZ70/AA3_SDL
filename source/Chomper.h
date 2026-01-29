#pragma once
#include "Object.h"
#include "RenderManager.h"
#include "InputManager.h"
#include "Enemy.h"
#define MAX 5

class Chomper : public Enemy
{
	bool finishEnter = false;
	bool finishCircle = false;
	int numberOfTimes = 0;
	int timeOfFrames = 300;

	int numberOfTimesWait = 0;
	int timeOfFrameWait = 500;
public:
	Vector2 center;
	float radius;
	float speed;
	float angle;

	float oldPosY;


	Chomper(float posX, float posY) : Enemy()
	{
		std::string texturePath = "resources/image.png";
		Vector2 size = { 1000, 1000 };
		Vector2 ofsset = { 0, 0 };
		_renderer = new ImageRenderer(_transform, texturePath, ofsset, size);
		Vector2 randomPosition = Vector2(rand() % RM->WINDOW_WIDTH, rand() % RM->WINDOW_HEIGHT);
		_transform->position = { posX, posY };
		_transform->scale = Vector2(.5f, .5f);
		_transform->rotation = 0.f;
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
	void MoveInCircle();
	void Move() override;
	void EnterInScene(int targetPosX) override;
	void ExitOutScene() override;

};