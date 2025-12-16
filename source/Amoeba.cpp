#include "Amoeba.h"
#include "Spawner.h"

void Amoeba::Update()
{
	Amoeba::Move();
	Object::Update();
}

void Amoeba::Render()
{
	_renderer->Render();
}

void Amoeba::Move()
{
	
	Amoeba::StartingMove();


	if (copy == false && finishCopy == false && finishStart == true)
	{
		Amoeba::CreateCopy();
	}
	else if (finishCircle == false && finishStart == true)
		Amoeba::MoveInCircle();
	else if (finishCircle == true)
		Amoeba::FinishMove();

}

void Amoeba::CreateCopy()
{
	Amoeba* amoeba = new Amoeba(_transform->position.x, _transform->position.y, true, 3, 0);
	Amoeba* amoeba1 = new Amoeba(_transform->position.x, _transform->position.y, true, -3, 0);
	Amoeba* amoeba2 = new Amoeba(_transform->position.x, _transform->position.y, true, 3, 3);
	Amoeba* amoeba3 = new Amoeba(_transform->position.x, _transform->position.y, true, 0, 3);
	Amoeba* amoeba4 = new Amoeba(_transform->position.x, _transform->position.y, true, 0, -3);
	Amoeba* amoeba5 = new Amoeba(_transform->position.x, _transform->position.y, true, -3, -3);
	Amoeba* amoeba6 = new Amoeba(_transform->position.x, _transform->position.y, true, 3, -3);
	Amoeba* amoeba7 = new Amoeba(_transform->position.x, _transform->position.y, true, -3, 3);
	
	SPAWNER.SpawnObject(amoeba);
	SPAWNER.SpawnObject(amoeba1);
	SPAWNER.SpawnObject(amoeba2);
	SPAWNER.SpawnObject(amoeba3);
	SPAWNER.SpawnObject(amoeba4);
	SPAWNER.SpawnObject(amoeba5);
	SPAWNER.SpawnObject(amoeba6);
	SPAWNER.SpawnObject(amoeba7);
	
	finishCopy = true;
}

void Amoeba::StartingMove()
{
	if (_transform->position.x <= RM->WINDOW_WIDTH/2)
	{
		_transform->position.x += 3.f;
	}
	else
		finishStart = true;

}

void Amoeba::MoveInCircle()
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

void Amoeba::FinishMove()
{
	if (_transform->position.x <= RM->WINDOW_WIDTH)
	{
		_transform->position.x -= 3.f;
	}
	else
		finishStart = true;
}
