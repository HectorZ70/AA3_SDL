#pragma once
#include "Object.h"
#include "RenderManager.h"
#include "ImageRenderer.h"
#include "InputManager.h"
#include "Bullet.h"
#include "Spawner.h"
#define OFFSET 30

class Cannon : public Object
{
	Vector2* currentPlayerPosition = nullptr;
	int ammunation = 0;
public:
	Cannon(Vector2* positionPlayer, int* ammunationCannon) : Object() //DO not pass by copy, it will break it
	{
		std::string texturePath = "";
		Vector2 size = { 1000, 1000 };
		Vector2 ofsset = { 0, 0 };
		_transform = new Transform();
		_renderer = new ImageRenderer(_transform, texturePath, ofsset, size);
		_transform->scale = Vector2(.5f, .5f);
		currentPlayerPosition = positionPlayer;
		ammunation = *ammunationCannon;
	}

	void Update() override;
	void Shoot();
};