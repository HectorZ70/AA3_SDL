#include "Background.h"

void Background::Update()
{
	Background::Move();

	ImageObject::Update();
}

void Background::Render()
{
	_renderer->Render();
}

void Background::Move()
{
	if (_transform->position.x >= 0)
	_transform->position.x -= 2;
	else
		_transform->position.x = 1024;
}
