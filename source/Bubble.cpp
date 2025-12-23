#include "Bubble.h"

void Bubble::Update()
{

	if (finishEnter == false)
		Bubble::EnterInScene(RM->WINDOW_WIDTH * 1/3);

	else if (finishEnter == true && finishCircle == false)
		Bubble::Move();

	else if (finishEnter == true && finishCircle == true)
		Bubble::ExitOutScene();
	Object::Update();
}

void Bubble::Render()
{
	_renderer->Render();
}

void Bubble::Move()
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

void Bubble::EnterInScene(int targetPosX)
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

void Bubble::ExitOutScene()
{
	if (_transform->position.x <= RM->WINDOW_WIDTH)
	{
		_transform->position = { _transform->position.x + 3.f  ,_transform->position.y };
	}
}
