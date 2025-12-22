#include "Borders.h"

void Border::Update()
{
	Border::Move();

	if (_other)
		CheckLoop(_other);

	ImageObject::Update();
}

void Border::Render()
{
	_renderer->Render();
}

void Border::Move()
{
		_transform->position.x -= 2;
}

void Border::SetBorders(Border* other)
{
	_other = other;
}

void Border::CheckLoop(Border* other)
{
	if (_transform->position.x <= -_width / 2)
	{
		_transform->position.x =
			other->_transform->position.x + _width;
	}
}
