#pragma once
#include "Enemy.h"
#include <iostream>


void Enemy::Update()
{

	Object::Update();
}

void Enemy::Render()
{
	_renderer->Render();
}

