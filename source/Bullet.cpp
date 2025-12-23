#include "Bullet.h"
#include "Enemy.h"
#include <iostream>

void Bullet::Update()
{
	_transform->position = { _transform->position.x + 20.f,_transform->position.y };

	if (directionBullet == 3)
		_transform->position = { _transform->position.x + 20.f  ,_transform->position.y };

	if (directionBullet == 1)
		_transform->position = { _transform->position.x, _transform->position.y - 20.f};

	if (directionBullet == 2)
		_transform->position = { _transform->position.x, _transform->position.y + 20.f };

	if (directionBullet == 0)
		_transform->position = { _transform->position.x - 20.f  ,_transform->position.y };

	Object::Update();
}

void Bullet::Render()
{
	_renderer->Render();
}



