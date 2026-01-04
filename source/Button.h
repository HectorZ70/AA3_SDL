#pragma once
#include "ImageObject.h"
#include <functional>

class Button : public ImageObject
{
public:
	typedef std::function <void()> OnClick;

	Button(OnClick onClick, float xPos, float yPos)
		: ImageObject("resources/image.png", Vector2(0.f, 0.f), Vector2(306.f, 562.f))
	{
		_onClick = onClick;

		_transform->position = { xPos, yPos };
		_transform->scale = { 1.f, 1.f };

		_physics->AddCollider(new AABB(_transform->position, _transform->size));
	}


	void Update() override;
	void Render() override;
	void OnHoverEnter();
	void OnHoverExit();
	void OnClicked();


private:
	bool _isHovered = false;
	OnClick _onClick;
};