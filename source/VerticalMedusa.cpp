#include "VerticalMedusa.h"

void VerticalMedusa::Update()
{
	VerticalMedusa::Move();

	Object::Update();
}

void VerticalMedusa::Render()
{
	_renderer->Render();
}

void VerticalMedusa::Move()
{
	if (_transform->position.y >= 0)
		_transform->position.y = _transform->position.y - 5;
	std::cout << _transform->position.y << std::endl;
}
