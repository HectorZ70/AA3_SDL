#pragma once
#include "Object.h"
#include "RenderManager.h"
#include "ImageRenderer.h"
#include "InputManager.h"
#include "Bullet.h"
#include "Spawner.h"
#define OFFSET 10

class Laser : public Object
{
	Vector2* currentPlayerPosition = nullptr;
	int ammunation = 0;
public:
	Laser(Vector2* positionPlayer, int* ammunationLaser) : Object() //DO not pass by copy, it will break it
	{
		std::string texturePath = "";
		Vector2 size = { 1000, 1000 };
		Vector2 ofsset = { 0, 0 };
		_transform = new Transform();
		_renderer = new ImageRenderer(_transform, texturePath, ofsset, size);
		_transform->scale = Vector2(0.3f, 0.3f);
		currentPlayerPosition = positionPlayer;
		ammunation = *ammunationLaser;
	}

	void Update() override;
	void Shoot();
};