#include "SpawnTwinTurrets.h"
#include "Spawner.h"
#include "Turrets.h"

void TwinTurretsPowerUp::Update()
{
}

bool TwinTurretsPowerUp::CollideWithPlayer()
{
	return false;
}

void TwinTurretsPowerUp::Change()
{
}

void TwinTurretsPowerUp::Effect(Player* player)
{
	Turret* turretsUp = new Turret(&player->GetPosition(), PositionRelative::UP);
	Turret* turretsDown = new Turret(&player->GetPosition(), PositionRelative::DOWN);
	SPAWNER.SpawnObject(turretsDown);
	SPAWNER.SpawnObject(turretsDown);
}
