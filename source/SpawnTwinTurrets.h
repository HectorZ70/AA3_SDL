#include "PowerUps.h"
#pragma once

class TwinTurretsPowerUp : public PowerUp
{
	TwinTurretsPowerUp(Vector2 position)
	{
		_transform->position = position;
	}
	void Update() override;
	bool CollideWithPlayer() override;
	void Change() override;
	void Effect() override;
};