#pragma once
#include "PowerUps.h"
#include "TestObject.h"
#define VELOCITY 2.f

class IncreaseVelocity : public PowerUp
{
public:
	IncreaseVelocity(Vector2 position)
	{
		_transform->position = position;
	}

	void Update() override;
	void CollideWithPlayer() override;
	void CollideWithBullet() override;
	void Change() override;
	void Effect(Player* player) override;
};