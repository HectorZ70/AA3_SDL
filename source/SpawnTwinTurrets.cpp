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
	Turret* turret = new Turret();
	Turret* turret = new Turret();
	SPAWNER.SpawnObject()
	SPAWNER.SpawnObject()
}
