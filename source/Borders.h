#pragma once
#include "ImageObject.h"

class Border : public ImageObject{
private:
	float _width;
	Border* _other;
public:
	Border(float xPos, float yPos) : ImageObject("resources/image.png", { 0.f, 0.f }, { 10.f, 100.f })
	{
		std::string texturePath = "resources/image.png";
		Vector2 size = { 1920, 50 };
		Vector2 ofsset = { 0, 0 };
		_transform = new Transform();
		_renderer = new ImageRenderer(_transform, texturePath, ofsset, size);

		_transform->position = { xPos , yPos };
		_transform->rotation = 0.f;
		_transform->size = size;
		_width = size.x;
	}

	void Update() override;
	void Render() override;

	void Move();
	void SetBorders(Border* other);
	void CheckLoop(Border* other);
};