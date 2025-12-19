#pragma once
#include "PowerUps.h"
#include "TestObject.h"


class ReplenisherEnergyLaser : public PowerUp
{
public:
	ReplenisherEnergyLaser(Vector2 position)
	{
		_transform->position = position;
	}

	void Update() override;
	bool CollideWithPlayer() override;
	bool CollideWithBullet() override;
	void Change() override;
	void Effect(Player* player) override;
};