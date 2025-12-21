#include "Laser.h"

void Laser::Update()
{
	_transform->position = *currentPlayerPosition;
	if (IM->GetEvent(SDLK_J, DOWN) && ammunation > 0)
	{
		Laser::Shoot();
		ammunation--;
	}

	Object::Update();
}

void Laser::Shoot()
{
	Bullet* bullet = new Bullet({_transform->position.x, _transform->position.y + OFFSET});
	SPAWNER.SpawnObject(bullet);
}

