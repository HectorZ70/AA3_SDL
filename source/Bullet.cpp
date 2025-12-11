#pragma once

#include "Bullet.h"
#include "Enemy.h"
#include <iostream>
#define WIDTH 1920

void Bullet::Update()
{
	_transform->position = { _transform->position.x + 20.f  ,_transform->position.y };

	if (_transform->position.x >= 500)
	{
		Bullet::Destroy();
		std::cout << "is destroyed" << std::endl;
	}
	Object::Update();
}

void Bullet::Render()
{
	_renderer->Render();
}



