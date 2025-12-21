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

	std::cout << _transform->position.x << " " << _transform->position.y << std::endl;
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
		}

		if (currentPlayerPosition->x <= anteriorPlayerPosition.x - OFFSET)
		{
			if (_transform->rotation > 90)
				_transform->rotation -= ROTATION;
			anteriorPlayerPosition.x = currentPlayerPosition->x;
		}
	}
	else if (upDown == PositionRelative::DOWN)
	{
		if (currentPlayerPosition->x >= anteriorPlayerPosition.x + OFFSET)
		{
			if (_transform->rotation > -90)
				_transform->rotation -= ROTATION;
			anteriorPlayerPosition.x = currentPlayerPosition->x;
		}

		if (currentPlayerPosition->x <= anteriorPlayerPosition.x - OFFSET)
		{
			if (_transform->rotation < 90)
				_transform->rotation += ROTATION;
			anteriorPlayerPosition.x = currentPlayerPosition->x;
		}
	}
}

void Turret::Shoot()
{
	Bullet* bullet = new Bullet(_transform->position);
	SPAWNER.SpawnObject(bullet);
}

int Turret::GetRotation()
{
	return _transform->rotation;
}
