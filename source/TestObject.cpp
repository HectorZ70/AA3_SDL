#include "TestObject.h"
#include "Spawner.h"

#include <iostream>
#include "Bullet.h"


void Player::Update()
{
		bool hasMoved = false;
		if (IM->GetEvent(SDLK_S, HOLD))
			{
			_transform->position = { _transform->position.x ,_transform->position.y + 5.f };
			}
		if (IM->GetEvent(SDLK_W, HOLD))
		{
			_transform->position = { _transform->position.x ,_transform->position.y - 5.f };
		}
		if (IM->GetEvent(SDLK_A, HOLD))
		{
			_transform->position = { _transform->position.x - 5.f  ,_transform->position.y};
		}
		if (IM->GetEvent(SDLK_D, HOLD))
		{
			_transform->position = { _transform->position.x + 5.f  ,_transform->position.y};
		}
		if (IM->GetEvent(SDLK_J, DOWN))
		{
			Player::Shoot();
		}	

		//std::cout << _transform->position.x << " " << _transform->position.y << "\n";

		Object::Update();

}

void Player::Render()
{
	_renderer->Render();
}

void Player::Shoot()
{
	Bullet* bullet = new Bullet(_transform->position);
	SPAWNER.SpawnObject(bullet);
}
