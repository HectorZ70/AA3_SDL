#include "Turrets.h"
#include "Spawner.h"
#include "Bullet.h"
#include <iostream>
void Turret::Update()
{
	Turret::Rotate();
	Turret::MoveAlongSide();
	
	if (IM->GetEvent(SDLK_J, DOWN))
	{
		Turret::Shoot();
	}

	Object::Update();
}

void Turret::Render()
{
	_renderer->Render();
}

void Turret::MoveAlongSide()
{
	_transform->position.x = currentPlayerPosition->x;
	if (upDown == PositionRelative::DOWN)
	{
		_transform->position.y = currentPlayerPosition->y + OFFSET;
	}
	else if (upDown == PositionRelative::UP)
	{
		_transform->position.y = currentPlayerPosition->y - OFFSET;
	}
}

void Turret::Rotate()
{
	if (upDown == PositionRelative::UP)
	{
		if (currentPlayerPosition->x >= anteriorPlayerPosition.x + OFFSET)
		{
			if (_transform->rotation < 270)
				_transform->rotation += ROTATION;
			anteriorPlayerPosition.x = currentPlayerPosition->x;

			if (_transform->rotation > 180)
			{
				rotation = 3;
			}
			else if (_transform->rotation < 180)
			{
				rotation = 0;
				std::cout << "B" << std::endl;
			}
			else
			{
				rotation = 1;
				std::cout << "B" << std::endl;
			}

			
		}

		if (currentPlayerPosition->x <= anteriorPlayerPosition.x - OFFSET)
		{
			if (_transform->rotation > 90)
				_transform->rotation -= ROTATION;
			anteriorPlayerPosition.x = currentPlayerPosition->x;

			if (_transform->rotation > 180)
				rotation = 3;
			else if (_transform->rotation < 180)
				rotation = 0;
			else
				rotation = 1;
		}
	}
	else if (upDown == PositionRelative::DOWN)
	{
		if (currentPlayerPosition->x >= anteriorPlayerPosition.x + OFFSET)
		{
			if (_transform->rotation > -90)
				_transform->rotation -= ROTATION;
			anteriorPlayerPosition.x = currentPlayerPosition->x;

			if (_transform->rotation > -90)
				rotation = 0;
			else if (_transform->rotation == 45)
				rotation = 3;
			else if(_transform->rotation <= 0)
				rotation = 2;
			std::cout << _transform->rotation << std::endl;
		}

		if (currentPlayerPosition->x <= anteriorPlayerPosition.x - OFFSET)
		{
			if (_transform->rotation < 90)
				_transform->rotation += ROTATION;
			anteriorPlayerPosition.x = currentPlayerPosition->x;

			if (_transform->rotation > -90)
				rotation = 0;
			else if (_transform->rotation == 45)
				rotation = 2;
			else if (_transform->rotation <= 0)
				rotation = 3;

		}
	}
}

void Turret::Shoot()
{
	Bullet* bullet = new Bullet(_transform->position, rotation);
	SPAWNER.SpawnObject(bullet);
}

int Turret::GetRotation()
{
	return _transform->rotation;
}
