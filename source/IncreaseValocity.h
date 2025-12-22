#pragma once
#include "PowerUps.h"
#include "TestObject.h"
#define VELOCITY 5.f

class IncreaseVelocity : public PowerUp
{
	float* playerVelocity = nullptr;
public:
	IncreaseVelocity(Vector2 position, float* velocity)
	{
		std::string texturePath = "resources/image.png";
		Vector2 size = { 1000, 1000 };
		Vector2 ofsset = { 0, 0 };
		_transform = new Transform();
		_renderer = new ImageRenderer(_transform, texturePath, ofsset, size);
		_transform->position = position;
		playerVelocity = velocity;
	}

	void Update() override;
	bool CollideWithPlayer() override;
	void Change() override;
	void Effect() override;
};