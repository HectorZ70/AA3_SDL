#pragma once
#include <string>
#include "ImageObject.h"

class Background : public ImageObject
{

public:
	Background(float yPos) : ImageObject("resources/image.png", {0.f, 0.f}, { 10.f, 100.f})
	{
		std::string texturePath = "resources/image.png";
		Vector2 size = { 100000, 100 };
		Vector2 ofsset = { 0, 0 };
		_transform = new Transform();
		_renderer = new ImageRenderer(_transform, texturePath, ofsset, size);
		float xPos = RM->WINDOW_WIDTH;

		_transform->position = { xPos , yPos / 2 };
		_transform->rotation = 0.f;
		_transform->size = size;
	}

	void Update() override;
	void Render() override;

	void Move();
};