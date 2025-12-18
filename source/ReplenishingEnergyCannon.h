#pragma once
#include "PowerUps.h"
#include "TestObject.h"


class ReplenisherEnergyCannon : public PowerUp
{
	ReplenisherEnergyCannon(Vector2 position)
	{
		_transform->position = position;
	}

	void Update() override;
	void CollideWithPlayer() override;
	void CollideWithBullet() override;
	void Change() override;
	void Effect(Player* player) override;
};