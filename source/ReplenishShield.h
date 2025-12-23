#pragma once
#include "PowerUps.h"
#include "Player.h"
#define MAX 100


class ReplenisherShield : public PowerUp
{
	bool hasBeenPlayed = false;
	int* shield = nullptr;
public:
	ReplenisherShield(Vector2 position, int* playerShield)
	{
		std::string texturePath = "resources/image.png";
		Vector2 size = { 1000, 1000 };
		Vector2 ofsset = { 0, 0 };
		_transform = new Transform();
		_renderer = new ImageRenderer(_transform, texturePath, ofsset, size);
		_transform->position = position;
		shield = playerShield;
	}

	void Update() override;
	bool CollideWithPlayer() override;
	void Change() override;
	void Effect() override;
};