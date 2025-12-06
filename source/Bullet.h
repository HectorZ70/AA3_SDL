#pragma once
#include "Object.h"
#include "RenderManager.h"
#include "InputManager.h"
#include "ImageRenderer.h"

class Bullet : public Object
{
public:
	Bullet() : Object()
	{
		std::string texturePath = "resources/image.png";
		Vector2 size = { 1000, 1000 };
		Vector2 ofsset = { 0, 0 };
		_transform = new Transform();
		_renderer = new ImageRenderer(_transform, texturePath, ofsset, size);
		Vector2 randomPosition = Vector2(rand() % RM->WINDOW_WIDTH, rand() % RM->WINDOW_HEIGHT);
		_transform->position = { 100, 100 };
		_transform->scale = Vector2(0.5f, 0.5f);
		_transform->rotation = 0.f;

	}
	void Update() override;
	void Render() override;

};
