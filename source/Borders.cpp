#include "Borders.h"

void Border::Update()
{
	Border::Move();

	ImageObject::Update();
}

void Border::Render()
{
	_renderer->Render();
}

void Border::Move()
{
	if (_transform->position.x >= 0)
		_transform->position.x -= 2;
	else
		_transform->position.x = 1024;
}