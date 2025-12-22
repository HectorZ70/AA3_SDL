#include "PowerUps.h"
#pragma once

class TwinTurretsPowerUp : public PowerUp
{
	bool hasBeenPlayed = false;
	Player* player = nullptr;
public:
	TwinTurretsPowerUp(Vector2 position, Player* playerptr)
	{
		std::string texturePath = "resources/image.png";
		Vector2 size = { 1000, 1000 };
		Vector2 ofsset = { 0, 0 };
		_transform = new Transform();
		_renderer = new ImageRenderer(_transform, texturePath, ofsset, size);

		_transform->position = position;
		player = playerptr;
	}
	void Update() override;
	bool CollideWithPlayer() override;
	void Change() override;
	void Effect() override;
};