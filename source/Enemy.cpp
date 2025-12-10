#pragma once
#include "Enemy.h"
#include <iostream>
#include <cmath>
#include <iomanip>

void Enemy::Update()
{
	angle += speed;

	_transform->position.x = _transform->position.x + cos(angle) * radius;
	_transform->position.y = _transform->position.y + sin(angle) * radius;
	std::cout << _transform->position.x << " " << _transform->position.y << std::endl;
	Object::Update();
}

void Enemy::Render()
{
	_renderer->Render();
}

