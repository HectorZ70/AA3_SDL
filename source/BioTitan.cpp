#include "BioTitan.h"

void BioTitan::Update()
{
	BioTitan::Shoot();
	if (currentFrame >= frameTime)
		currentFrame = 0;



	BioTitan::Render();
}

void BioTitan::Render()
{
	_renderer->Render();
}

void BioTitan::Shoot()
{
	if (currentFrame <= frameTime)
	{
		Bullet* bullet = new Bullet(_transform->position, 0);
		SPAWNER.SpawnObject(bullet);
		currentFrame++;
	}
}

void BioTitan::Damage()
{
	health--;
}

void BioTitan::Die()
{
	BioTitan::Destroy();
}


