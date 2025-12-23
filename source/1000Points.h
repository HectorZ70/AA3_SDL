#pragma once
#include "PowerUps.h"
#include "Spawner.h"
#include "Player.h"
#define POINTS 1000

class Points : public PowerUp
{
	bool hasBeenPlayed = false;
	int* points = nullptr;
public:

	Points(Vector2 position, int* score)
	{
		std::string texturePath = "resources/image.png";
		Vector2 size = { 1000, 1000 };
		Vector2 ofsset = { 0, 0 };
		_transform = new Transform();
		_renderer = new ImageRenderer(_transform, texturePath, ofsset, size);
		_transform->position = position;
		points = score;
	}

	void Update() override;
	bool CollideWithPlayer() override;
	void Change() override;
	void Effect() override;
};