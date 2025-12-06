#pragma once

#include "Bullet.h"
#include <iostream>


void Bullet::Update()
{

	_transform->position = { _transform->position.x + 5.f  ,_transform->position.y };

	Object::Update();

}

void Bullet::Render()
{
	_renderer->Render();
}



