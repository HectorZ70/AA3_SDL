#pragma once
#include "Enemy.h"
#include <iostream>
#include <cmath>
#include <iomanip>

void Enemy::Update()
{
	if (finishEnter == false)
		Enemy::EnterInScene(100);

	else if (finishEnter == true && finishCircle == false)
		Enemy::MoveInCircles();

	else if (finishEnter == true && finishCircle == true)
		Enemy::ExitOutScene();

	Object::Update();
}

void Enemy::Render()
{
	_renderer->Render();
}

void Enemy::MoveInCircles()
{
	angle += speed;

	_transform->position.x = center.x + cos(angle) * radius;
	_transform->position.y = center.y + sin(angle) * radius;
	std::cout << _transform->position.x << " " << _transform->position.y << " " << oldPosY << std::endl;

	if (_transform->position.y > center.y - 3 && _transform->position.y < center.y+3)
	{
		numberOfTimes++;
		if (numberOfTimes == 4)
		finishCircle = true;
	}

}

void Enemy::EnterInScene(int targetPosX)
{
	if (_transform->position.x >= targetPosX)
	{
		_transform->position = { _transform->position.x - 3.f  ,_transform->position.y };
	}
	else
	{
		finishEnter = true;
		center = _transform->position;
	}
}

void Enemy::ExitOutScene()
{
	if (_transform->position.x <= 1024)
	{
		_transform->position = { _transform->position.x + 3.f  ,_transform->position.y };
	}
}

