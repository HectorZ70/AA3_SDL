#pragma once

#include "Bullet.h"
#include <iostream>


Bullet::~Bullet()
{
	delete _transform;
	delete _renderer;
}

void Bullet::Update()
{
	_transform->position = { _transform->position.x + 20.f  ,_transform->position.y };

	Object::Update();
}

void Bullet::Render()
{
	_renderer->Render();
}



