#include "Turrets.h"
#include "Spawner.h"
#include "Bullet.h"

void Turret::Update()
{
	Rotate();
	MoveAlongSide();

	Turret::Render();
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
		_transform->position.y = OFFSET + currentPlayerPosition->y;
	}
	else if (upDown == PositionRelative::UP)
	{
		_transform->position.y = OFFSET - currentPlayerPosition->y;
	}
}

void Turret::Rotate()
{
	if (currentPlayerPosition->x >= anteriorPlayerPosition.x + OFFSET)
	{
		_transform->rotation += 30;
	}

	if (currentPlayerPosition->x <= anteriorPlayerPosition.x - OFFSET)
	{
		_transform->rotation -= 30;
	}
}

void Turret::Shoot()
{
	Bullet* bullet = new Bullet(*currentPlayerPosition);
	SPAWNER.SpawnObject(bullet);
}
