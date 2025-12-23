#pragma once
#include "Circler.h"
#include <iostream>
#include <cmath>
#include <iomanip>

void Circler::Update()
{
	if (finishEnter == false)
		Circler::EnterInScene(100);

	else if (finishEnter == true && finishCircle == false)
		Circler::Move();

	else if (finishEnter == true && finishCircle == true)
		Circler::ExitOutScene();

	Object::Update();
}

void Circler::Render()
{
	_renderer->Render();
}

void Circler::Move()
{
	angle += speed;

	_transform->position.x = center.x + cos(angle) * radius;
	_transform->position.y = center.y + sin(angle) * radius;

	if (_transform->position.y > center.y - 3 && _transform->position.y < center.y + 3)
	{
		numberOfTimes++;
		if (numberOfTimes == 4)
			finishCircle = true;
	}

}

void Circler::EnterInScene(int targetPosX)
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

void Circler::ExitOutScene()
{
	if (_transform->position.x <= 1024)
	{
		_transform->position = { _transform->position.x + 3.f  ,_transform->position.y };
	}
}

