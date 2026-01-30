#include "Chomper.h"

void Chomper::Update()
{
	if (numberOfTimesWait <= timeOfFrameWait)
	{
		numberOfTimesWait++;
	}

	if (numberOfTimesWait >= timeOfFrameWait)
	{
		if (!finishCircle)
			MoveInCircle();
		else
			Move();
	}
	//std::cout << _transform->position.x << " " << _transform->position.y << std::endl;
	Chomper::Render();
	Object::Update();
}

void Chomper::Render()
{
	_renderer->Render();
}

void Chomper::MoveInCircle()
{
	
	angle += speed;

	_transform->position.x = center.x + cos(angle) * radius;
	_transform->position.y = center.y + sin(angle) * radius;

	if (_transform->position.y > center.y - 3 && _transform->position.y < center.y + 3)
	{
		numberOfTimes++;
		if (numberOfTimes == 10)
			finishCircle = true;
	}

}

void Chomper::Move()
{
	if (_transform->position.x >= 0)
		_transform->position.x = _transform->position.x - 5;
}

void Chomper::EnterInScene(int targetPosX)
{
}

void Chomper::ExitOutScene()
{
}
