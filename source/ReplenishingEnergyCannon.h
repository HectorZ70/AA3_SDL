#pragma once
#include "PowerUps.h"
#include "Player.h"
#define MAX 100


class ReplenisherEnergyCannon : public PowerUp
{
	bool hasBeenPlayed = false;
	int* cannonAmmunation = nullptr;
public:
	ReplenisherEnergyCannon(Vector2 position, int* ammunation)
	{
		std::string texturePath = "resources/image.png";
		Vector2 size = { 1000, 1000 };
		Vector2 ofsset = { 0, 0 };
		_transform = new Transform();
		_renderer = new ImageRenderer(_transform, texturePath, ofsset, size);
		_transform->position = position;
		cannonAmmunation = ammunation;
	}

	void Update() override;
	bool CollideWithPlayer() override;
	void Change() override;
	void Effect() override;
};