#include "TestObject.h"
#include "Spawner.h"

#include <iostream>
#include "Bullet.h"


void Player::Update()
{
		bool hasMoved = false;
		Player::Move();
		Object::Update();
}

void Player::Render()
{
	_renderer->Render();
}

void Player::Move()
{
	if (_transform->position.x >= 0)
		if (IM->GetEvent(SDLK_A, HOLD))
		{
			_transform->position = { _transform->position.x - 5.f  ,_transform->position.y };
		}

	if (_transform->position.x <= RM->WINDOW_WIDTH)
		if (IM->GetEvent(SDLK_D, HOLD))
		{
			_transform->position = { _transform->position.x + 5.f  ,_transform->position.y };
		}

	if (_transform->position.y >= 0)
		if (IM->GetEvent(SDLK_W, HOLD))
		{
			_transform->position = { _transform->position.x ,_transform->position.y - 5.f };
		}

	if (_transform->position.y <= RM->WINDOW_HEIGHT)
		if (IM->GetEvent(SDLK_S, HOLD))
		{
			_transform->position = { _transform->position.x ,_transform->position.y + 5.f };
		}
	
	if (IM->GetEvent(SDLK_J, DOWN))
	{
		Player::Shoot();
	}
}

void Player::Shoot()
{
	Vector2 direction = { 1.0f, 0.0f };   
	float offset = 30.0f;                

	Vector2 spawnPos = _transform->position + direction * offset;

	Bullet* bullet = new Bullet(spawnPos);
	SPAWNER.SpawnObject(bullet);
}
