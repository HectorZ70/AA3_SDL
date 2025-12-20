#include "Turrets.h"

void Turret::Update()
{
}

void Turret::MoveAlongside()
{
	_transform->position.x = currentPlayerPosition->x;
	if (upDown == DOWN)
	{
		_transform->position.y = OFFSET + currentPlayerPosition->y;
	}
	else if (upDown == UP)
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
}
