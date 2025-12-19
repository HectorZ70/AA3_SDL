#pragma once
#include "PowerUps.h"
#include "TestObject.h"


class ReplenisherShield : public PowerUp
{
public:
	ReplenisherShield(Vector2 position)
	{
		_transform->position = position;
	}

	void Update() override;
	bool CollideWithPlayer() override;
	bool CollideWithBullet() override;
	void Change() override;
	void Effect(Player* player) override;
};