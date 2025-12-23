#include "Beholder.h"



void Beholder::Update()
{
	if (_transform->position.y >= RM->WINDOW_HEIGHT)
		onFloor = Start::FLOOR;
	else if (_transform->position.y <= 0)
		onFloor = Start::CELLING;
	else
		onFloor = Start::NONE;

	Beholder::Move();

	Object::Update();
}

void Beholder::Render()
{
	_renderer->Render();
}

void Beholder::Move()
{
	if (numberOfFrames >= limitOfFrames)
	{
		forceX = rand() % 4;
		forceY = rand() % 4;
	}

	if (onFloor == Start::FLOOR)
	{
		yMod = -1;
		if (numberOfFrames >= limitOfFrames)
		{
			xMod = (std::rand() % 2 == 0) ? -1 : 1;
			numberOfFrames = 0;
		}
		
	}

	else if (onFloor == Start::CELLING)
	{
		yMod = 1;
		if (numberOfFrames >= limitOfFrames)
		{
			xMod = (std::rand() % 2 == 0) ? -1 : 1;
			numberOfFrames = 0;
		}
	}

	else if (onFloor == Start::NONE)
	{
		if (numberOfFrames >= limitOfFrames)
		{
			xMod = (std::rand() % 2 == 0) ? -1 : 1;
			yMod = (std::rand() % 2 == 0) ? -1 : 1;
			numberOfFrames = 0;
		}
	}
	_transform->position.x += forceX * xMod;
	_transform->position.y += forceY * yMod;
	numberOfFrames++;
}
