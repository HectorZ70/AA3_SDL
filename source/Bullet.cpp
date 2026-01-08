#include "Bullet.h"
#include "Enemy.h"
#include <iostream>

void Bullet::Update()
{
	if (directionBullet == PLAYERRIGHT)
		_transform->position = { _transform->position.x + PLAYERVELOCITY  ,_transform->position.y };

	if (directionBullet == PLAYERDOWN)
		_transform->position = { _transform->position.x, _transform->position.y - PLAYERVELOCITY };

	if (directionBullet == PLAYERUP)
		_transform->position = { _transform->position.x, _transform->position.y + PLAYERVELOCITY };

	if (directionBullet == PLAYERLEFT)
		_transform->position = { _transform->position.x - PLAYERVELOCITY  ,_transform->position.y };

	Object::Update();
}

void Bullet::Render()
{
	_renderer->Render();
}



