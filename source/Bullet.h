#pragma once
#include "Object.h"
#include "RigidBody.h"
#include "RenderManager.h"
#include "InputManager.h"
#include "ImageRenderer.h"

class Bullet : public Object
{
	int directionBullet;
public:
	Bullet(Vector2 playerPosition, int direction) : Object()
	{
		std::string texturePath = "resources/image.png";
		Vector2 size = { 1000, 1000 };
		Vector2 ofsset = { 0, 0 };
		_transform = new Transform();
		_renderer = new ImageRenderer(_transform, texturePath, ofsset, size);
		
		Vector2 randomPosition = Vector2(rand() % RM->WINDOW_WIDTH, rand() % RM->WINDOW_HEIGHT);
		_transform->position = { playerPosition };
		_transform->scale = Vector2(0.1f, 0.1f);
		_transform->rotation = 0.f;
		directionBullet = direction;

	}

	void Update() override;
	void Render() override;

};
