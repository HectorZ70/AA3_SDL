#pragma once
#include "PowerUps.h"
#include "TestObject.h"


class ReplenisherEnergyCannon : public PowerUp
{
public:
	ReplenisherEnergyCannon(Vector2 position)
	{
		_transform->position = position;
	}

	void Update() override;
	bool CollideWithPlayer() override;
	void Change() override;
	void Effect(Player* player) override;
};