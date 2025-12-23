#include "Background.h"

void Background::Update()
{
	Background::Move();

	if (_other)
		CheckLoop(_other);

	ImageObject::Update();
}

void Background::Render()
{
	_renderer->Render();
}

void Background::Move()
{
	_transform->position.x -= 2;
}

void Background::SetBackground(Background* other)
{
	_other = other;
}

void Background::CheckLoop(Background* other)
{
	if (_transform->position.x <= -_width / 2)
	{
		_transform->position.x =
			other->_transform->position.x + _width;
	}
}
