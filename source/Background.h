#pragma once
#include <string>
#include "ImageObject.h"

class Background : public ImageObject
{

public:
	Background(float xPos, float yPos) : ImageObject("resources/background.png", {0.f, 0.f}, { 10.f, 100.f})
	{
		std::string texturePath = "resources/background.png";
		Vector2 size = { 1920, 1080 };
		Vector2 ofsset = { 0, 0 };
		_transform = new Transform();
		_renderer = new ImageRenderer(_transform, texturePath, ofsset, size);

		_transform->position = { xPos , yPos };
		_transform->rotation = 0.f;
		_transform->size = size;
	}

	void Update() override;
	void Render() override;

	void Move();
};