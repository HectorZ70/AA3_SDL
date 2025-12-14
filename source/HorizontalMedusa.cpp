#include "HorizontalMedusa.h"
#include <iostream>

void HorizontalMedusa::Update()
{
	HorizontalMedusa::Move();

	Object::Update();
}

void HorizontalMedusa::Render()
{
	_renderer->Render();
}

void HorizontalMedusa::Move()
{
	if (_transform->position.x >= 0)
	_transform->position.x = _transform->position.x - 5;
	std::cout << _transform->position.x << std::endl;
}
