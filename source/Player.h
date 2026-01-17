#pragma once
#include <Vector>
#include "ImageObject.h"
#include "RenderManager.h"
#include "InputManager.h"
#include "ImageRenderer.h"
#define ENERGYCANNONMAX 100
#define ENERGYLASERMAX 100
#define SHIELDMAX 100

class Player : public ImageObject
{

public:
	int score;
	int energyCannon = 1;
	int energyLaser = 1;
	float velocity;
	int shield;
	std::string texturePath = "resources/image.png";
	Vector2 size = { 1000, 1000 };
	Vector2 offset = { 0, 0 };
	Player() : ImageObject(texturePath, offset, size)
	{
		
		_transform = new Transform();
		_renderer = new ImageRenderer(_transform, texturePath, offset, size);
		Vector2 randomPosition = Vector2(rand() % RM->WINDOW_WIDTH, rand() % RM->WINDOW_HEIGHT);
		_transform->position = { 100, 100 };
		_transform->scale = Vector2(0.5f, 0.5f);
		_transform->rotation = 0.f;
		score = 0;
		energyCannon = 10;
		energyLaser = 10;
		velocity = 5.f;
		shield = 100;
	}
	void Update() override;
	void Render() override;
	void Move();
	void Shoot();

	void IncreaseScore(int increaseScore) { score += increaseScore; }
	int& GetScore() { return score; }
	int& GetShield() { return shield; }
	void DecreaseEnergyCannon() { energyCannon--; }
	int GetEnergyCannon() { return energyCannon; }
	Vector2& GetPosition() { return _transform->position; }
	int& GetEnergyLaserAmmunation() { return energyLaser; }
	int& GetEnergyCannonAmmunation() { return energyCannon; }
	float& GetVelocity() { return velocity; }
};