#include "Cannons.h"

void Cannon::Update()
{
	_transform->position = *currentPlayerPosition;
	if (IM->GetEvent(SDLK_J, DOWN) && ammunation > 0)
	{
		Cannon::Shoot();
		ammunation--;
	}

	Object::Update();
}

void Cannon::Shoot()
{
	Bullet* bullet = new Bullet({ _transform->position.x, _transform->position.y + OFFSET });
	Bullet* secondBullet = new Bullet({ _transform->position.x, _transform->position.y - OFFSET });
	SPAWNER.SpawnObject(bullet);
	SPAWNER.SpawnObject(secondBullet);
}
