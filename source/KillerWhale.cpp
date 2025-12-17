#include "KillerWhale.h"

void KillerWhale::Update()
{
	KillerWhale::Move();

	Object::Update();
}

void KillerWhale::Render()
{
	_renderer->Render();
}

void KillerWhale::Move()
{
	if (onFloor == CELLING)
	{
		_transform->position.x -= 2.5f;
		_transform->position.y += 5.5f;
	}
	else
	{
		_transform->position.x -= 2.5f;
		_transform->position.y -= 5.5f;
	}
	if (_transform->position.y >= RM->WINDOW_HEIGHT)
		onFloor = FLOOR;
	else if (_transform->position.y <= 0)
		onFloor = CELLING;
}
