#include "SpawnTwinTurrets.h"
#include "Spawner.h"
#include "Turrets.h"
#include "Player.h"

void TwinTurretsPowerUp::Update()
{
	TwinTurretsPowerUp::Effect();
	Object::Update();
}

bool TwinTurretsPowerUp::CollideWithPlayer()
{
	return false;
}

void TwinTurretsPowerUp::Change()
{
}

void TwinTurretsPowerUp::Effect()
{
	if (hasBeenPlayed == false)
	{
		Turret* turretsUp = new Turret(&player->GetPosition(), PositionRelative::UP);
		Turret* turretsDown = new Turret(&player->GetPosition(), PositionRelative::DOWN);
		SPAWNER.SpawnObject(turretsUp);
		SPAWNER.SpawnObject(turretsDown);
		hasBeenPlayed = true;
	}
}
